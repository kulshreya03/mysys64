#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

using namespace std;

sem_t x, y;
pthread_t writerthreads[100], readerthreads[100];
int readercount = 0;
int sharedData = 0; // Renamed to avoid ambiguity

void* reader(void* param) {
    int id = *((int*)param);

    sem_wait(&x);
    readercount++;
    if (readercount == 1)
        sem_wait(&y); // First reader locks writer
    sem_post(&x);

    cout << "Reader " << id << " is reading data: " << sharedData 
         << " (Total readers: " << readercount << ")\n";
    usleep(100000); // Simulate reading

    sem_wait(&x);
    readercount--;
    if (readercount == 0)
        sem_post(&y); // Last reader unlocks writer
    sem_post(&x);

    cout << "Reader " << id << " is leaving (Remaining readers: " << readercount << ")\n";
    usleep(100000); 
    return nullptr;
}

void* writer(void* param) {
    int id = *((int*)param);

    //cout << "Writer " << id << " is trying to enter\n";
    sem_wait(&y); // Writer lock

    sharedData += 10; // Simulate writing by modifying the shared data
    cout << "Writer " << id << " is writing new data: " << sharedData << "\n";
    usleep(150000); // Simulate writing
    cout << "Writer " << id << " is leaving\n";
    usleep(100000); 

    sem_post(&y);

    return nullptr;
}

int main() {
    int n;
    cout << "Enter number of readers/writers: ";
    cin >> n;
    cout << endl;

    int ids[n];
    sem_init(&x, 0, 1);
    sem_init(&y, 0, 1);

    for (int i = 0; i < 3; i++) {
        ids[i] = i + 1;
        pthread_create(&readerthreads[i], nullptr, reader, &ids[i]);
        pthread_create(&writerthreads[i], nullptr, writer, &ids[i]);
    }

    for (int i = 0; i < 3; i++) {
        pthread_join(readerthreads[i], nullptr);
        pthread_join(writerthreads[i], nullptr);
    }

    sem_destroy(&x);
    sem_destroy(&y);

    return 0;
}
