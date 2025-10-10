# Basic Terminal Commands

## 1. `pwd`
**Purpose:** Prints the current directory (i.e., where you are in the file system).

**Example:**
```bash
$ pwd
/Users/username
```

## 2. `ls`
**Purpose:** Lists the files and folders in the current directory.

**Example:**
```bash
$ ls
Desktop   Documents   Downloads   Pictures
```

## 3. `cd [directory]`
**Purpose:** Changes the directory you're in. Replace `[directory]` with the folder path.

**Example:**
```bash
$ cd Documents
$ cd /Users/username/Downloads
```

## 4. `mkdir [folder_name]`
**Purpose:** Creates a new directory (folder).

**Example:**
```bash
$ mkdir NewFolder
```

## 5. `rm [file_name]`
**Purpose:** Deletes a file (be careful, this doesn't move it to the Trash!).

**Example:**
```bash
$ rm file.txt
```

## 6. `rmdir [folder_name]`
**Purpose:** Deletes an empty folder.

**Example:**
```bash
$ rmdir OldFolder
```

## 7. `rm -r [folder_name]`
**Purpose:** Deletes a folder and all of its contents (be cautious when using this one).

**Example:**
```bash
$ rm -r myFolder
```

## 8. `cp [source] [destination]`
**Purpose:** Copies a file or folder from the source to the destination.

**Example:**
```bash
$ cp file.txt /Users/username/Documents/
```

## 9. `mv [source] [destination]`
**Purpose:** Moves a file or folder from the source to the destination (also used for renaming).

**Example:**
```bash
$ mv file.txt /Users/username/Documents/
$ mv oldname.txt newname.txt
```

## 10. `touch [file_name]`
**Purpose:** Creates a new, empty file with the given name.

**Example:**
```bash
$ touch newfile.txt
```

## 11. `cat [file_name]`
**Purpose:** Displays the contents of a file.

**Example:**
```bash
$ cat myfile.txt
```

## 12. `open [file_name]`
**Purpose:** Opens a file with its default app (like opening a `.txt` file in TextEdit).

**Example:**
```bash
$ open file.txt
```

## 13. `clear`
**Purpose:** Clears the Terminal screen.

**Example:**
```bash
$ clear
```

---

# Advanced Commands

## 1. `sudo [command]`
**Purpose:** Runs a command with superuser (admin) privileges. You'll be prompted for your password.

**Example:**
```bash
$ sudo rm -r /Users/username/OldFiles
```

## 2. `chmod [permissions] [file_name]`
**Purpose:** Changes the permissions of a file or directory. Example: give read, write, and execute permissions.

**Example:**
```bash
$ chmod 755 script.sh
```

## 3. `chown [user] [file_name]`
**Purpose:** Changes the owner of a file or folder.

**Example:**
```bash
$ sudo chown username:groupname file.txt
```

## 4. `top`
**Purpose:** Displays real-time system processes and resource usage (CPU, memory, etc.).

**Example:**
```bash
$ top
```

## 5. `ps aux`
**Purpose:** Lists all running processes.

**Example:**
```bash
$ ps aux
```

## 6. `kill [PID]`
**Purpose:** Terminates a process by its process ID (PID).

**Example:**
```bash
$ kill 1234
```

## 7. `df -h`
**Purpose:** Displays disk space usage in a human-readable format (e.g., GB, MB).

**Example:**
```bash
$ df -h
```

## 8. `du -sh [directory]`
**Purpose:** Shows the size of a directory and its contents in a human-readable format.

**Example:**
```bash
$ du -sh /Users/username/Documents
```

---

# Networking Commands

## 1. `ping [hostname or IP]`
**Purpose:** Checks the network connection to a host or IP address.

**Example:**
```bash
$ ping google.com
```

## 2. `ifconfig`
**Purpose:** Displays network interface information (IP address, etc.).

**Example:**
```bash
$ ifconfig
```

## 3. `curl [URL]`
**Purpose:** Retrieves content from a URL (you can use this to check if a website is up).

**Example:**
```bash
$ curl https://example.com
```

---

# File Search Commands

## 1. `find [path] -name [file_name]`
**Purpose:** Searches for a file by name in a specific directory.

**Example:**
```bash
$ find /Users/username/Documents -name "file.txt"
```

## 2. `grep [pattern] [file]`
**Purpose:** Searches for a specific pattern or string within a file.

**Example:**
```bash
$ grep "hello" file.txt
```

---

# Other Useful Commands

## 1. `history`
**Purpose:** Shows the list of all previously used commands.

**Example:**
```bash
$ history
```

## 2. `exit`
**Purpose:** Closes the Terminal window or ends the current Terminal session.

**Example:**
```bash
$ exit
```

## 3. `man [command]`
**Purpose:** Displays the manual or help documentation for a command.

**Example:**
```bash
$ man ls
```

---

# Example of a Simple Task

Let's say you want to copy a file from one directory to another, delete an old file, and change the permissions of the copied file. Here's how you might do it:

```bash
$ cd /Users/username/Documents
$ cp report.txt /Users/username/Desktop/
$ rm old_report.txt
$ chmod 644 /Users/username/Desktop/report.txt
```