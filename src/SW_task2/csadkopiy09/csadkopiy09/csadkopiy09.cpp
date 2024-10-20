#include <iostream>
#include <boost/asio.hpp>
#include <thread>
#include <chrono>

using namespace boost;

int main() {
    asio::io_service io;
    asio::serial_port serial(io);

    try {
        // Відкриваємо послідовний порт і встановлюємо швидкість
        serial.open("COM3"); 
        serial.set_option(asio::serial_port_base::baud_rate(9600)); 

        // Надсилаємо повідомлення на Arduino
        std::string message = "Hello, Arduino Uno R3!\n";
        if (asio::write(serial, asio::buffer(message))) {
            // Та в консоль
            std::cout << "Client -> Arduino: " << message; 
        }

        // Додаємо затримку для отримання відповіді
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); 

        // Отримуємо відповідь
        char buffer[256];
        // Зчитуємо отримані дані
        size_t bytesRead = serial.read_some(asio::buffer(buffer)); 
        // Додаємо нульовий термінатор для коректного виводу
        buffer[bytesRead] = '\0'; 
        // Виводимо відповідь
        std::cout << "Arduino -> Client: " << buffer << std::endl; 
        // Закриваємо порт
        serial.close(); 
    }
    catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
