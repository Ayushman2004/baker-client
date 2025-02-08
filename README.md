# Baker: C/C++ Package Manager

Baker is a lightweight and efficient package manager for C/C++ libraries. It simplifies the process of downloading, managing, and linking libraries in C/C++ projects. The system consists of two primary components:

1. **Baker Client:** A C++ application designed to efficiently handle package management on the client side.
2. **Baker Server:** A Java-based backend built using Spring Boot, providing scalable and stable package hosting and management.

---

## Baker Client

### Overview
The Baker Client is a lightweight C++ tool designed to operate efficiently with minimal system resource requirements. It organizes library files in structured directories and provides easy integration with CMake.

### Key Features
- **Resource Efficiency:** Built in C++ for optimal performance.
- **Directory Structure:** Predefined folders for better library management:
  - `header/`: Contains library headers.
  - `src/`: Stores source files.
  - `bin/`: Holds binary files.
  - `debug/`: Contains debug versions of binaries and libraries.
- **CMake Integration:** Provide a cmake configuration file to link all libraries seamlessly.
- **REST Communication:** Uses `restclient` to communicate with the Baker Server.

### Installation
#### Prerequisites
- C++ compiler (e.g., `g++`)
- `restclient` library installed
- `nlohmann/json.hpp` library installed

#### Build Instructions
1. Clone the repository in the root dir:
   ```bash
   git clone https://github.com/Ayushman2004/baker-client.git
   cd baker-client
   ```

2. Compile the client:
   - vcpkg prefered for compiling `main.cpp`

3. Run the client:
   ```bash
   .\baker.exe
   ```

### Usage
1. **Install a package:**
   ```bash
   .\baker.exe install <package_name>
   ```
   The library files will be stored in the appropriate folders (`header/`, `src/`, `bin/`, `debug/`) for easy access.

2. **Linking with CMake:**
   Use the pre-configured CMake file by Baker to link libraries:
   ```bash
   include("C:/baker-client/CommonLibs.cmake")
   ```

---


## License
This project is licensed under the Apache-2.0 License.
