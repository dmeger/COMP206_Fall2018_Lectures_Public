# Frequently Asked Questions about Assignment 1

## Where does my code have to be located to run correctly?

Your code should be able to run no matter where the .bash file is located, both with respect to the present working directory, and with respect to the paths given as arguments. Just think about the fact that "ls" is located in /bin/ls, but it works equally well no matter where you cd to or which directory you want to inspect.

How can you achieve this? The trick is to let the shell work for you. $1 and $2 arguments must be "proper" paths given by the user, so you can simply pass them to any command you need without modifying them. Do not hard-code, such as "./$1" or "~/COMP206_A1/$1". Both of those examples will restrict where your code works and would lose you marks.

For testing, ensure you can cd to a different location entirely and still have your code work. For example, run this test, which assumes you unzipped the provided file in the COMP206_A1 folder within your home directory and also placed your bash script there:
$ cd ~ 
$ mkdir temp_junk_test
$ cd temp_junk_test
$ bash ~/COMP206_A1/q2_decrypt.bash ~/COMP206_A1/Q2/codebook.txt ~/~/COMP206_A1/secret_message.txt

Does it work for you?
