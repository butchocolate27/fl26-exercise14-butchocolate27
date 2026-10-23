# ECE 3574 Exercise 14: QDataStream

`write_file` writes a `QList<QString>` to `temp.dat`. `read_file` checks the
magic number and file version, then reads and prints the list. Both programs
use the same QDataStream format.

Requires CMake, a C++17 compiler, and Qt 6 Core.

```sh
cmake -S . -B build
cmake --build build
cd build
./write_file
./read_file
```

Run both programs from the same directory so they use the same `temp.dat`.
