# Huffman-File-Compression
 Huffman File Compression. Program compressess the input file and store into a file.

This code contains total of 4 class files namely Huffman, LinkList, Node, and Compare. And for the queue class, we are using the predefined queue.


1.	Huffman.cpp contains a class that has specific functions to create both the optimal as well as the non-optimal Huffman tree. This class has 8 functions. First is findUnique function which gives us the unique characters by removing all the duplicates. findFrequency function calculates the frequency of a given character from the string which in also passed as a parameter. createBinary function creates binary code for each character in the string and stores it in the link list. encodeData and decodeData functions encode and decode the binary generated from code respectively. orderedBinary function creates the ordered tree using a priority queue. unorderedBinary function creates the unordered tree using an ordinary queue. The last function in the Huffman class is calculateCompression which gives us the compression ratio by calculating ABR and dividing it by 8.


2.	Linkedlist.cpp contains the functionality for a singly linked list. The purpose of this class is to store the binary string codes associated with each character in a single node along with the associated frequency.


3.	Node.cpp file contains the node class for the linked list. Each node contains the right-left pointer for the tree and data members to store the binary associated with each unique character in a given string and also stores their frequency.


4.	The last class we created is compared class which contains only one operator function which returns true or false by comparing the frequencies of the given nodes. This class is used in the declaration of the predefined priority queue in the orderedBinary function.


**How Does the Code Works?**


Main.cpp contains the driver code which first takes the file name as input. After that, it opens that file and extracts the string from it. If the file in empty or fails to open it displays appropriate messages accordingly. Then we find the unique character from the extracted string and store it in unique variable. After that, we calculate the frequency of the unique character from the original string by calling the findUnique function in a loop. Along with characters, we insert the frequencies in the link list.
After displaying the original and unique string on the console we are creating an ordered tree that provides more compression using the priority queue. And all this generation of binary and assigning into the unique character of the string is done in the orderedBinary function off the Huffman class and then displaying the tree by display function. After this, we are creating an encoded string from the original string and then decode that encoded string. In the end, we are displaying both strings along with the compression ratio.
Now we are creating another link list and copying the previously created link list into the new one. This link list is used for creating the unordered tree which provides less compression as compared to the ordered tree. This operation can be done with the ordinary queue. This link list contains the frequency, and unique characters along with their binary as it is a copy of the previous link list. Now we are replacing the binary in this link list with the new ones by passing it in UnorderedBinary function. After that, the program displays the decoded and encoded string generated from an unordered tree. And then the compression ratio is displayed.


**Summary**


For larger strings or text solution is always more optimal than an optimized solution and most of the time difference is clear for small strings too. But there will be no difference if the string is very small and each character has exactly one frequency. The same tree is constructed from both solutions if all have the same frequency.


**Results**


Input File Name: file.txt


File.txt contains the string: aadbaaca


Output is as follows:


Optimized Compression Ration: 4.92308


Unoptimized Compression Ration: 4
