# CryptiC Module Responsibilities

1. main.c
   - Entry point.
   - Calls login() and routes to menu system.

2. auth.c
   - User login & authentication.
   - Password hashing.
   - Retry logic.

3. encrypt.c
   - XOR file encryption logic.
   - Accepts key from user.
   - Handles file I/O for text files.

4. decrypt.c
   - Reverses encryption using same key.
   - Checks file extension or metadata.

5. filehide.c
   - Implements hide/unhide feature.
   - Uses system() to run OS commands.

6. logger.c
   - Appends logs to log.txt.
   - Timestamped action logs.

7. utils.c
   - Helper functions:
     - getTimeStamp()
     - fileExists()
     - clearScreen() (platform-independent)
     - pressEnterToContinue()
