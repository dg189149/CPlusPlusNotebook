Simple Terminal Notepad (C++)

Features:
- Open a file: `./notepad filename`
- Print buffer with line numbers: `p`
- Append/Insert lines (multiline entry, finish with a single `.` on a line): `a <n>`, `i <n>`
- Edit one line: `e <n>`
- Delete a line: `d <n>`
- Find substring: `f <pattern>`
- Save: `w` or `w <filename>`
- Quit: `q` (prompts to save if modified)

Build:
- `make`

Usage examples:
- `./notepad notes.txt` - open file
- `p` - print contents
- `a 3` - append after line 3; then type lines and `.` to finish
- `w` - save (if opened from file) or `w newname.txt` to save to a new file

Notes:
- This is a very small and simple line-oriented editor. It doesn't implement a full-screen interface.
- If you want full-screen editing, I can add an ncurses-based mode in a follow-up.
