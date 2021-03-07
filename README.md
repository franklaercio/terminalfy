<h2 align="center"> 
  Terminalfy - C++
</h1>

<p align="center">
  <a href="https://www.linkedin.com/in/frank-laercio/">
    <img alt="Made by franklaercio" src="https://img.shields.io/badge/Linkedin-Made%20by%20franklaercio-blue">
  </a>

  <img alt="License" src="https://img.shields.io/badge/license-MIT-brightgreen">
   <a href="https://github.com/franklaercio/terminalfyr/stargazers">
    <img alt="Stargazers" src="https://img.shields.io/github/stars/franklaercio/terminalfy?style=social">
  </a>
</p>

### Resume

This application was a challenge proposed by the Linguagem de Programação I, as part of unit one. This is an application developed in c ++ for creating music and playlist. It is possible to add a song, remove a song, list the registered songs, create a playlist, add a song to a playlist, remove a song from a playlist, list all the playlist and list the songs in the playlist.

### Getting Started

For started you need to install **gcc** and **make**

### Running

For execute the code you need to run the following code:

```bash
make all
```

```bash
./terminalfy
```

### Example of execute part 1

1. Type a number option (int)
2. Adding 3 songs (option 1)
3. List all songs (option 3)
4. Remove one music (option 2)
5. Find one music add (option 4)
6. Create a playlist (option 5)
7. List all playlist (option 8)
8. Add one music at playlist (option 6)
9. List all music of playlist (option 9)
10. Remove one music of playlist (option 7)

### Example of execute part 2

1. A: Menu > Type 10 > Type 1 > Type title as teste1 > Type songwriter as teste1 > Type 1 >
      Type title as teste2 > Type songwriter as teste2 > Type 0 > In menu type 3 for list all musics
1. B: Menu > Type 1 > Type title as teste1 > Type songwriter as teste1 > Menu > Type 1 >
      Type title as teste2 > Type songwriter as teste2 > Menu > Type 1 > Type title as teste3 > Type songwriter as teste3 > 
      Menu > Type 11 > Type 1 > Type teste1 > Type 1 > Type teste3 > Type 0 > Menu > Type 3
1. C: Test case: line 24 in songlist.h
2. A: Menu > Tyoe 12 > Type 1 > Type title as a > Type songwriter as a > Type 1 > Type title as b > Type songwriter as b >
      Type 0 > Type 1 > Type title as a > Type songwriter as a > Type 1 > Type title as c > Type songwriter as c >   
2. B: Menu > Type 1 > Type title as a > Type songwriter as a > Menu > Type 1 > Type title as b > Type songwriter as b >
      Menu > Type 3 > Menu > Type 13 > Menu > Type 3 
2. C: Menu > Type 1 > Type title as a > Type songwriter as a > Menu > Type 1 > Type title as b > Type songwriter as b >
      Menu > Type 3 > Menu > Type 14 > Type title as c > Type songwriter as c > Menu > Type 3
3. A: Menu > Type 1 > Type title as a > Type songwriter as a > Menu > Type 1 > Type title as b > Type songwriter as c >
      Menu > Type 1 > Type title as c > Type songwriter as c > Menu > Type 5 > Type title as teste1 > Menu > Type 5 > Type title as teste2
      Menu > Type 15 > Type teste1 > Type 1 > Type a > Type 1 > Type b > Type 0 > Menu > Type 15 > Type teste2 > Type 1 > Type a > Type 1 > Type c > Type 0 >
      Menu > Type 9 > Type teste1 > Menu > Type 9 > Type teste2
3. B: Menu > Type 1 > Type title as a > Type songwriter as a > Menu > Type 1 > Type title as b > Type songwriter as b >
      Menu > Type 1 > Type title as c > Type songwriter as c > Menu > Type 5 > Type title as teste1 >
      Menu > Type 15 > Type teste1 > Type 1 > Type a > Type 1 > Type b > Type 1 > Type c > Type 0 >
      Menu > Type 9 > Type teste1 > Menu > Type 16 > Type teste1 > Type 1 > Type a > Type 1 > Type c > Type 0
      Menu > Type 9 > Type teste1
3. C: Test case: line 87 in playlist.h    
4. A: Menu > Type 1 > Type title as a > Type songwriter as a > Menu > Type 1 > Type title as b > Type songwriter as b >
      Menu > Type 1 > Type title as c > Type songwriter as c > Menu > Type 5 > Type title as teste1 > Menu > Type 5 > Type title as teste2
      Menu > Type 15 > Type teste1 > Type 1 > Type a > Type 1 > Type b > Type 0 > Menu > Type 15 > Type teste2 > Type 1 > Type a > Type 1 > Type c > Type 0 >
      Menu > Type 17 > Type teste1 > Type teste2 > Type teste3 > Menu > Type 9 > Type teste3 
4. B: Menu > Type 1 > Type title as a > Type songwriter as a > Menu > Type 1 > Type title as b > Type songwriter as b >
      Menu > Type 1 > Type title as c > Type songwriter as c > Menu > Type 15 > Type teste1 > Type 1 > Type a > Type 1 > Type b > Type 0 > 
      Menu > Type 18 > Type test1 > Type c > Menu > Type 9 > Type teste1 
4. C: Menu > Type 1 > Type title as a > Type songwriter as a > Menu > Type 1 > Type title as b > Type songwriter as b >
      Menu > Type 1 > Type title as c > Type songwriter as c > Menu > Type 5 > Type title as teste1 > Menu > Type 5 > Type title as teste2
      Menu > Type 15 > Type teste1 > Type 1 > Type a > Type 1 > Type b > Type 0 > Menu > Type 15 > Type teste2 > Type 1 > Type a > Type 1 > Type c > Type 0 >
      Menu > Type 19 > Type teste1 > Type teste2 > Type teste3 > Menu > Type 9 > Type teste3  
4. D: Menu > Type 1 > Type title as a > Type songwriter as a > Menu > Type 1 > Type title as b > Type songwriter as b >
      Menu > Type 1 > Type title as c > Type songwriter as c > Menu > Type 15 > Type teste1 > Type 1 > Type a > Type 1 > Type b > Type 0 > 
      Menu > Type 20 > Type test1 > Type b > Menu > Type 9 > Type teste1  
4. E: Menu > Type 1 > Type title as a > Type songwriter as a > Menu > Type 1 > Type title as b > Type songwriter as b >
      Menu > Type 15 > Type teste1 > Type 1 > Type a > Type 1 > Type b > Type 0 > 
      Menu > Type 21 > Type test1 > Menu > Type 9 > Type teste1  
4. F: Menu > Type 1 > Type title as a > Type songwriter as a > Menu > Type 1 > Type title as b > Type songwriter as b >
      Menu > Type 1 > Type title as c > Type songwriter as c > Menu > Type 5 > Type title as teste1 > Menu > Type 5 > Type title as teste2
      Menu > Type 15 > Type teste1 > Type 1 > Type a > Type 1 > Type b > Type 0 >
      Menu > Type 22 > Type teste1 > Type c > Menu > Type 9 > Type teste3   

### Problems

1. I did not do the music consultation recursively
2. I didn't do the play next feature
3. In the main file I could have done the operations in small functions 
4. When you delete a song, it is not deleted from the playlist

### Contributing

Please read [CONTRIBUTING.md](http://contributing.md/) for details on our code of conduct, and the process for submitting pull requests to us.

### Authors

- **Frank Laércio** - [franklaercio](https://github.com/franklaercio)

See also the list of [contributors](https://github.com/franklaercio//terminalfy/contributors) who participated in this project.

### Acknowledgments

- C++
- LinkedList
- POO