
# Relocation Assistant

Relocation Assistant is a C++ and Qt cross-platform desktop application that allows users to compare every census tract in the United States based on geographic and socio-economic factors. This application was created for the COP3530 final project.




## Demo

The .exe for this project can be found here: 

https://drive.google.com/file/d/14rngYTeXKWQXQrKCg3XhzivFELAWHs6A/view?usp=sharing


## Run Locally

### Prerequisites

* C++ compiler with C++17 support

* Qt Framework

* Make

* Git

### Setup

Clone the project

```bash
  git clone https://github.com/colemmorgan/COP3530-Project3.git
```

Go to the project directory

```bash
  cd COP3530-Project3
```
### Download Data

Download the CSV file from: 

https://drive.google.com/file/d/195spE2KaXjxXqDbmLFONoZ2Lo2DVx5Do/view?usp=sharing

Save the file as data.csv in the project root directory

### Build the Project

```bash
  # Create build directory
  mkdir build
  cd build

  # Configure the project
  cmake ..

  # Build the project
  make

  ./COP3530-Project3 # or your application name
```

