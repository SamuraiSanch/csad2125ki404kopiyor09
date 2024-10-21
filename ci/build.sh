с#!/bin/bash

# Створюємо директорію для збірки
mkdir -p build
cd build

# Використовуємо CMake для генерації збірочних файлів
cmake ..

# Збираємо проект
cmake --build . --config Release

# Повертаємось назад
cd ..
