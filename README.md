# MULTITHREADED-FILE-COMPRESSION-TOOL

*COMPANY*: CODTECH IT SOLUTION 

*NAME*: AYMAN AHAMAD

*INTERN IN*: CT04DF890

*DOMAIN*: C++

*DURATION*: 4 WEEK

*MENTOR*: NEELA SANTOSH

## 📌 Internship Task-2 Report  
Project Title: Multithreaded File Compression Tool  
Technology: C++ (Multithreading + File I/O)

For my second internship task at CodTech, I was asked to build a tool that could compress and decompress files using multithreading. The focus was mainly on improving performance and understanding how threads can run in parallel to make things faster. This task helped me a lot in learning not only file operations but also the concept of concurrent programming.

I started this project by refreshing my basics of multithreading in C++. I already knew about file handling from the first task, so now the goal was to combine that with threads. I went through some online blogs, C++ documentation, and video tutorials to understand how to safely use threads and share resources like variables or file streams between them.

For compression, I used a basic run-length encoding logic (RLE). This means that if a file has "aaaabbbcc", it gets converted to "a4b3c2". It’s a simple and fast way to show how compression works. The main logic was divided into chunks, and each thread handled one chunk of the data. The threads ran in parallel, processed their respective parts, and then added their output to a common buffer. I used std::mutex to avoid conflicts when multiple threads tried to write at the same time.

I made sure to test this with different sizes of input files, and the performance difference was clearly visible compared to the single-threaded version. The code was kept simple so that it’s easy to understand and maintain. It reads a file, divides its content, creates threads to compress the content in chunks, and finally writes the output to a new file.

One of the biggest takeaways from this task was understanding thread synchronization. Without using mutex, my program was giving weird outputs because multiple threads were writing to the same stream at once. Once I locked the output stream using a mutex, the result became stable and correct. Debugging multithreaded code is not easy, but with patience and repeated testing, I was able to figure it out.

Another thing I kept in mind was writing clean and understandable code. I didn’t rely on copy-pasting — I wrote everything from scratch by first planning how the flow would go. This really helped me understand what each line is doing. The project felt like a real-world scenario where performance actually matters, so the learning was practical and not just theoretical.

In the end, this project gave me confidence in using multithreading in C++ and also made me more comfortable with file I/O. I feel ready to take on more complex problems now, and I’m proud that I could finish this task independently.

This has been one of the most productive parts of my internship so far.

##output

