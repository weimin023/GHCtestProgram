#include "source.h"

int main()
{
    const std::vector<std::string> fnames = { 
        "./testdata/file_0.txt",
        "./testdata/file_1.txt",
        "./testdata/file_2.txt",
        "./testdata/file_3.txt",
        "./testdata/file_4.txt",
        "./testdata/file_5.txt",
        "./testdata/file_6.txt",
        "./testdata/file_7.txt",
        "./testdata/file_8.txt",
        "./testdata/file_9.txt",
        "./testdata/file_10.txt",
        "./testdata/file_11.txt",
        "./testdata/file_12.txt",
        "./testdata/file_13.txt",
        "./testdata/file_14.txt",
        "./testdata/file_15.txt"
    }; // 16 files
    
    collectIDProcess2 test(fnames);
    test.run();
    
}

