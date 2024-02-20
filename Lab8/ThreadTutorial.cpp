//
// Created by ivanh on 20.02.2024.
//

#include <iostream>
#include <thread>
#include <chrono>

// �������, ������� ����� ����������� � ������
void threadFunction() {
    for (int i = 0; i < 5; ++i) {
        std::cout << "Thread running..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main() {
    std::cout << "Start of the main thread." << std::endl;

    // �������� ������ � ������ ������� � ���� ������
    std::thread t(threadFunction);

    // ������������ ���������� ��������� ������ �� 3 �������
    std::this_thread::sleep_for(std::chrono::seconds(3));

    // �������� ���������� ������
    t.join();

    std::cout << "The main thread has finished running." << std::endl;

    return 0;
}