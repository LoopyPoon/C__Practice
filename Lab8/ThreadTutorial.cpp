//
// Created by ivanh on 20.02.2024.
//

#include <iostream>
#include <thread>
#include <chrono>

// Функция, которая будет выполняться в потоке
void threadFunction() {
    for (int i = 0; i < 5; ++i) {
        std::cout << "Thread running..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main() {
    std::cout << "Start of the main thread." << std::endl;

    // Создание потока и запуск функции в этом потоке
    std::thread t(threadFunction);

    // Приостановка выполнения основного потока на 3 секунды
    std::this_thread::sleep_for(std::chrono::seconds(3));

    // Ожидание завершения потока
    t.join();

    std::cout << "The main thread has finished running." << std::endl;

    return 0;
}