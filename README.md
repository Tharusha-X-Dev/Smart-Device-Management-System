# Smart Device Management System

A robust, console-based Smart Device Management System developed in **C++**, leveraging Object-Oriented Programming (OOP) principles and **smart pointers** for safe, modern memory management.

This system lets users manage smart devices—such as projectors, door locks, air conditioning systems, room lighting, and security cameras—via an interactive, menu-driven console interface.

---

## ✨ Features

### 🛠 Device Management
- **Add** new smart devices  
- **Remove** existing devices  
- **View** all devices  
- **View details** for individual devices

### ⚡ Device Control
- **Activate** and **deactivate** devices
- Interact with **device-specific features**

### 🔗 Connection Management
- View **connected** and **disconnected** devices
- Toggle device connection status

### 🎛 Device-Specific Functionality
- **Projector:** Change input source, adjust brightness
- **Air Conditioning:** Adjust target temperature
- **Door Lock:** Lock/unlock, track the last opened user
- **Room Lighting:** Adjust brightness
- **Security Camera:** Change camera quality, configure power source

---

## 🏗️ Object-Oriented Concepts Used

- **Abstraction:**  
  Implemented via the abstract base class `Device`.

- **Inheritance:**  
  Specialized devices inherit from `Device`:
  - `Projector`
  - `DoorLock`
  - `RoomLighting`
  - `AirConditioning`
  - `SecurityCamera`

- **Polymorphism:**  
  Virtual methods such as `interactionEvent()`, `editSpecificSettings()`, and `viewInfo()` allow seamless runtime polymorphism.

- **Encapsulation:**  
  Device attributes are kept protected/private and exposed via public interfaces.

---

## 🧠 Smart Pointer Usage

Smart pointers are utilized for safe and efficient memory management:
- Uses `std::unique_ptr<Device>` in `std::vector<std::unique_ptr<Device>>`
- Ensures:
  - Automatic memory cleanup
  - Safe ownership semantics
  - Memory leak prevention
  - RAII-based resource management

---

## 🛠️ Technologies Used

- **C++**
- **Visual Studio** (2022 or newer)
- **STL (Standard Template Library)**
- **Smart Pointers** (`std::unique_ptr`)
- **Object-Oriented Principles**

---

## 📂 Project Structure

```
├── Device.hpp / Device.cpp
├── DeviceManager.hpp / DeviceManager.cpp
├── Projector.hpp / Projector.cpp
├── DoorLock.hpp / DoorLock.cpp
├── RoomLighting.hpp / RoomLighting.cpp
├── AirConditioning.hpp / AirConditioning.cpp
├── SecurityCamera.hpp / SecurityCamera.cpp
├── InputValidator.hpp / InputValidator.cpp
├── ConsoleMenu.hpp / ConsoleMenu.cpp
├── main.cpp
```

---

## 📝 UML Class Diagram

[Class Diagram](Class-Diagram-for-the-Solution.png)


---

## 🧩 Memory Management

This project integrates **Visual Studio CRT memory leak detection**, ensuring thorough debugging and dynamic memory verification.

---

## 🚀 How to Run

### Requirements
- Visual Studio 2022 or newer
- C++17 or later

### Steps

1. **Clone** the repository  
   ```bash
   git clone https://github.com/Tharusha-X-Dev/Smart-Device-Management-System.git
   ```

2. **Open** the `.sln` file in Visual Studio

3. **Build** the solution

4. **Run** the project

---

## 🎓 Example Concepts Demonstrated

- Runtime polymorphism & dynamic dispatch
- Smart pointer ownership semantics
- Composition & dependency relationships
- Modular design & separation of concerns
- Input validation & defensive programming

---

## 👤 Author

**K.A Tharusha Lakshan Dananjaya**

---

> _Empowering your console with smart device management, modern C++ style!_
