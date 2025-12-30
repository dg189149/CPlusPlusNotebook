#include <bits/stdc++.h>
using namespace std;

struct Buffer {
    vector<string> lines;
    string filename;
    bool modified = false;

    void clear() { lines.clear(); modified = true; filename.clear(); }
    bool load(const string &fname) {
        ifstream in(fname);
        if (!in) return false;
        lines.clear();
        string line;
        while (getline(in, line)) lines.push_back(line);
        filename = fname;
        modified = false;
        return true;
    }
    bool save(const string &fname) {
        ofstream out(fname);
        if (!out) return false;
        for (size_t i = 0; i < lines.size(); ++i) out << lines[i] << (i+1<lines.size()?"\n":"");
        filename = fname;
        modified = false;
        return true;
    }
    void print(size_t from = 1, size_t to = (size_t)-1) const {
        if (lines.empty()) { cout << "(empty)\n"; return; }
        if (from == 0) from = 1;
        if (to == (size_t)-1) to = lines.size();
        from = min(from, lines.size()+1);
        to = min(to, lines.size());
        for (size_t i = from; i <= to; ++i) cout << i << "\t" << lines[i-1] << "\n";
    }
    void insert_after(size_t n, const vector<string> &block) {
        if (n > lines.size()) n = lines.size();
        lines.insert(lines.begin()+n, block.begin(), block.end());
        modified = true;
    }
    void insert_before(size_t n, const vector<string> &block) {
        if (n == 0) n = 1;
        if (n > lines.size()+1) n = lines.size()+1;
        lines.insert(lines.begin()+n-1, block.begin(), block.end());
        modified = true;
    }
    bool edit_line(size_t n, const string &content) {
        if (n == 0 || n > lines.size()) return false;
        lines[n-1] = content; modified = true; return true;
    }
    bool delete_line(size_t n) {
        if (n == 0 || n > lines.size()) return false;
        lines.erase(lines.begin() + (n-1)); modified = true; return true;
    }
    vector<size_t> find(const string &pat) const {
        vector<size_t> res;
        for (size_t i = 0; i < lines.size(); ++i) if (lines[i].find(pat) != string::npos) res.push_back(i+1);
        return res;
    }
};

static void show_help() {
    cout << "Commands:\n"
         << "  help                - show this help\n"
         << "  open <file>         - open file\n"
         << "  new                 - start a new buffer\n"
         << "  p [from] [to]       - print lines (defaults: 1 end)\n"
         << "  a <n>               - append after line n; enter multiline mode, end with single '.'\n"
         << "  i <n>               - insert before line n; multiline mode, end with '.'\n"
         << "  e <n>               - edit line n (single-line)\n"
         << "  d <n>               - delete line n\n"
         << "  f <pattern>         - find pattern (substring search)\n"
         << "  w [file]            - save (optional filename)\n"
         << "  q                   - quit (prompts to save if modified)\n"
         << "  help                - show this message\n";
}

static vector<string> read_block() {
    cout << "-- enter text, single '.' on a line to finish --\n";
    vector<string> block;
    string line;
    while (true) {
        if (!getline(cin, line)) break;
        if (line == ".") break;
        block.push_back(line);
    }
    return block;
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Buffer buf;
    if (argc >= 2) {
        string fname = argv[1];
        if (!buf.load(fname)) cout << "Could not open '" << fname << "', starting with empty buffer.\n";
    }

    cout << "Simple Terminal Notepad - plain C++\nType 'help' for commands.\n";

    string line;
    while (true) {
        cout << "> ";
        if (!getline(cin, line)) break;
        if (line.empty()) continue;
        istringstream iss(line);
        string cmd; iss >> cmd;
        if (cmd == "help") {
            show_help();
        } else if (cmd == "open") {
            string fname; iss >> ws; if (!(iss >> fname)) { cout << "missing filename\n"; continue; }
            if (!buf.load(fname)) cout << "Failed to open '"<<fname<<"'\n"; else cout << "Opened '"<<fname<<"' ("<<buf.lines.size()<<" lines).\n";
        } else if (cmd == "new") {
            if (buf.modified) {
                cout << "Buffer modified. Use 'w' to save or 'new' again to discard. Type 'new' to confirm: ";
                string confirm; getline(cin, confirm);
                if (confirm != "new") { cout << "Aborted.\n"; continue; }
            }
            buf.clear(); cout << "New buffer.\n";
        } else if (cmd == "p") {
            size_t a=1,b=(size_t)-1; if (iss >> a) iss >> b;
            buf.print(a,b);
        } else if (cmd == "a") {
            size_t n; if (!(iss >> n)) { cout << "requires line number\n"; continue; }
            auto block = read_block(); buf.insert_after(n, block); cout << "Inserted "<<block.size()<<" lines.\n";
        } else if (cmd == "i") {
            size_t n; if (!(iss >> n)) { cout << "requires line number\n"; continue; }
            auto block = read_block(); buf.insert_before(n, block); cout << "Inserted "<<block.size()<<" lines.\n";
        } else if (cmd == "e") {
            size_t n; if (!(iss >> n)) { cout << "requires line number\n"; continue; }
            if (n==0 || n > buf.lines.size()) { cout << "invalid line number\n"; continue; }
            cout << "current: " << buf.lines[n-1] << "\n> ";
            string newl; if (!getline(cin, newl)) newl = "";
            buf.edit_line(n, newl); cout << "Line "<<n<<" updated.\n";
        } else if (cmd == "d") {
            size_t n; if (!(iss >> n)) { cout << "requires line number\n"; continue; }
            if (buf.delete_line(n)) cout << "Deleted line "<<n<<".\n"; else cout << "invalid line number\n";
        } else if (cmd == "f") {
            string pat; if (!(iss >> ws) || !getline(iss, pat) || pat.empty()) { cout << "requires pattern\n"; continue; }
            // trim leading ws
            size_t pos = pat.find_first_not_of(' '); if (pos!=string::npos) pat = pat.substr(pos);
            auto res = buf.find(pat);
            if (res.empty()) cout << "No matches.\n"; else { for (auto ln: res) cout << ln << "\t" << buf.lines[ln-1] << "\n"; }
        } else if (cmd == "w") {
            string fname; if (iss >> fname) {
                if (buf.save(fname)) cout << "Saved '"<<fname<<"'.\n"; else cout << "Failed to save to '"<<fname<<"'.\n";
            } else {
                if (buf.filename.empty()) { cout << "No filename. Use 'w <file>'.\n"; }
                else { if (buf.save(buf.filename)) cout << "Saved '"<<buf.filename<<"'.\n"; else cout << "Failed to save '"<<buf.filename<<"'.\n"; }
            }
        } else if (cmd == "q") {
            if (buf.modified) {
                cout << "Buffer modified. Save before quit? (y/n): "; string ans; if (!getline(cin, ans)) ans = "n";
                if (!ans.empty() && (ans[0]=='y' || ans[0]=='Y')) {
                    if (buf.filename.empty()) { cout << "Enter filename: "; string fn; if (!getline(cin, fn)) fn = ""; if (fn.empty()) { cout << "Abort quit (no filename).\n"; continue; } if (!buf.save(fn)) { cout << "Save failed. Abort quit.\n"; continue; }
                    } else {
                        if (!buf.save(buf.filename)) { cout << "Save failed. Abort quit.\n"; continue; }
                    }
                }
            }
            break;
        } else {
            cout << "Unknown command: '"<<cmd<<"' (type 'help')\n";
        }
    }

    cout << "Goodbye.\n";
    return 0;
}
