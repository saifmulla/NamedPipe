# NamedPipe

Pipes are Inter Process Communication (IPC) mechanism provided by OS to facilitate communication between similar or different applications, such as sharing data, messages, executing tasks on same computer or across computers over a computer network. A classical example is Client-Server execution models where clients request certain work or files etc from server and the server delievers it. Pipe concept can be understood using water pipe analogy, it allow water to flow into one end and water flows out from other end.

On Linux pipe mechanism is provided using FIFO API, on Windows it is available using Pipes Api provided by windows native library. On Window the pipe mechanism are of two types, **Anonymous Pipes** and **NamedPipes**  

### Anonymous Pipes
As the name implies its a unnamed pipe, allows one way communication between process based on parent-child terminology on same computer locally.

### NamedPipe  
This is broader concept in pipe implementation, it allows one and two way communication between application locally and remotely over internet network.

## Updates

progresive

2. writing simple code (90 mins)
    - code compiling few simple tests and simple codes running.
1. constribution time 2-3 hrs
    - reading and understanding NamedPipes concept and API documentation.
    - Initial project setup and compiling successfully on windows from github.
    - Configuring and compiling code using cmake and using visual studio IDE.
    - Checking and adapting to compile simple c++ code on windows using VC++.
    - Virtuallising and setting up windows with all environment on MAC.
