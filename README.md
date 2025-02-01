
# Non-Blocking Wait Implementation

This project implements a non-blocking alternative to the `wait` system call in Linux. The application handles terminated child processes and ensures that no child process becomes a zombie. It prints the PID, exit status, and the reason for termination (signal or normal exit) of each terminated child process.

## Features
- Non-blocking wait functionality using `waitpid` with `WNOHANG`.
- Proper handling of terminated child processes.
- Displays child process PID, exit status, and termination reason.
- Prevents child processes from becoming zombies.

## Files
- `non_blocking_wait.h`: Header file containing function declarations.
- `non_blocking_wait.c`: Implementation file for the non-blocking wait logic.
- `main.c`: Entry point to test the non-blocking wait functionality.

## Compilation

To compile the program, use the following command:

```bash
gcc -o non_blocking_wait main.c non_blocking_wait.c
```

This will create the executable `non_blocking_wait`.

## Usage

To run the program, simply execute the following command:

```bash
./non_blocking_wait
```

### Expected Output

The program will fork several child processes and, as they terminate, it will print details about each child process, including:
- Child PID
- Exit status
- Termination reason (signal or normal exit)

Example output:

```
Child PID 12345 created
Child PID 12346 created
Child PID 12347 created
Child PID 12348 created
Child PID 12349 created
Child PID 12345 terminated normally with exit status 100
Child PID 12346 terminated normally with exit status 101
Child PID 12347 terminated by signal 6
Child PID 12348 terminated normally with exit status 102
Child PID 12349 terminated normally with exit status 103
```

## Testing

To test the functionality of the program, you can use the following methods:

1. **Run the program normally**:
   ```bash
   ./non_blocking_wait
   ```

2. **Simulate child process termination by signal**:
   Modify `main.c` to include a call to `abort()` in one of the child processes (e.g., child 3):
   ```c
   if (i == 3) {
       abort();  // Simulate child termination by signal
   }
   ```

3. **Check for zombie processes**:
   After running the program, check the process list to ensure no zombie processes:
   ```bash
   ps aux | grep Z
   ```

4. **Forcefully kill the parent process**:
   You can kill the parent process using the `kill` command to ensure the children are properly handled:
   ```bash
   ps aux | grep non_blocking_wait
   kill -9 <parent_pid>
   ```

5. **Check the process list**:
   After the program has run, use the `ps` command to verify that all child processes were reaped by the parent process:
   ```bash
   ps aux | grep non_blocking_wait
   ```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- Inspired by the need to manage child processes without blocking the parent in Unix-like systems.