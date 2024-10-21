#include <iostream>
#include <boost/asio.hpp>
#include <thread>
#include <chrono>

using namespace boost;

int main() {
    asio::io_service io;
    asio::serial_port serial(io);

    try {
        // Open the serial port and set the speed
        serial.open("COM3"); 
        serial.set_option(asio::serial_port_base::baud_rate(9600)); 

        // Sending a message to Arduino
        std::string message = "Hello, Arduino Uno R3!\n";
        if (asio::write(serial, asio::buffer(message))) {
            // And to Console
            std::cout << "Client -> Arduino: " << message; 
        }

        // Add a delay to receive a response
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); 

        // Get an answer
        char buffer[256];
        // Read the received data
        size_t bytesRead = serial.read_some(asio::buffer(buffer)); 
        // Add a zero terminator for correct output
        buffer[bytesRead] = '\0'; 
        // Show the answer
        std::cout << "Arduino -> Client: " << buffer << std::endl; 
        // Close the port
        serial.close(); 
    }
    catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
