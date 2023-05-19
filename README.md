## File Recovery

This C program recovers JPEG images from a forensic image file. It reads the image file, scans for JPEG signatures, and saves each found JPEG image as a separate file.

### Usage

To use the program, follow these steps:

1. Compile the program using a C compiler of your choice (e.g., GCC).
2. Run the compiled executable, providing the forensic image file as a command-line argument.

```
./recover IMAGE
```

### Program Logic

The program follows the following steps to recover JPEG images:

1. Check the command-line arguments to ensure that an image file is provided. If not, display a usage message and exit.
2. Open the image file for reading.
3. Define a buffer to read blocks of data from the image file.
4. Define variables to track the current JPEG file number, whether a new file needs to be created, and the output file pointer.
5. While reading blocks of data from the image file:
   - Check if the block contains the signature of a JPEG image file.
   - If a new JPEG image is found, close the previous output file (if any), generate a new file name using a three-digit file number, open the new file for writing, and increment the file number.
   - If an output file is open, write the block to the file.
6. Close the last output file (if any) and close the image file.
7. Exit the program.

### Example

Suppose the program is run with the following command:

```
./recover forensic_image
```

The program will scan the "forensic_image" file, search for JPEG signatures, and save each found JPEG image as a separate file with a unique name (e.g., "001.jpg", "002.jpg", etc.).

### Error Handling

The program includes basic error handling, such as checking for command-line argument validity, file opening errors, and file closing errors.

### Limitations

This program assumes that the forensic image file contains only JPEG images and that the JPEG files are not fragmented.

Feel free to modify and use this code according to your needs.
