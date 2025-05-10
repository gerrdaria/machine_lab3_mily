# cmake_minimum_required(VERSION 3.10)
# project(AutomatProject)

# set(CMAKE_CXX_STANDARD 17)


# add_executable(automat
#     main.cpp
#     automat/mili.cpp
#     automat/mura.cpp
#     automat/minimizirovan.cpp
# )
cmake_minimum_required(VERSION 3.10)
project(AutomatProject)

set(CMAKE_CXX_STANDARD 17)

# Добавляем подпапки
add_subdirectory(automat)
add_subdirectory(testing)

# Главный исполняемый файл
add_executable(automat_main main.cpp)

# Подключаем библиотеку автоматов
target_link_libraries(automat_main automat_lib)
target_include_directories(tests PRIVATE extern/catch2)
