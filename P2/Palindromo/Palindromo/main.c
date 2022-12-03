//
//  main.c
//  Palindromo
//
//  Created by Leonardo Alejandro González López on 19/10/21.
//  Copyright © 2021 UASLP. All rights reserved.
//

// A O(n^2) time and O(1) space
// program to find the longest
// palindromic substring
#include <stdio.h>
#include <string.h>

// A utility function to print
// a substring str[low..high]
void printSubStr(char* str, int low, int high)
{
    for (int i = low; i <= high; ++i)
        printf("%c", str[i]);
}

// This function prints the longest
// palindrome substring (LPS)
// of str[]. It also returns the
// length of the longest palindrome
int longestPalSubstr(char* str)
{

    // The result (length of LPS)
    int maxLength = 1;

    int start = 0;
    unsigned long len = strlen(str);

    int low, high;

    // One by one consider every
    // character as center point of
    // even and length palindromes
    for (int i = 1; i < len; ++i) {
        // Find the longest even length
        // palindrome with center points
        // as i-1 and i.
        low = i - 1;
        high = i;
        while (low >= 0 && high < len && str[low] == str[high]) {
            --low;
            ++high;
        }
    
        // Move back to the last possible valid palindrom substring
        // as that will anyway be the longest from above loop
        ++low;
        --high;
        if (str[low] == str[high] && high - low + 1 > maxLength) {
            start = low;
            maxLength = high - low + 1;
        }

        // Find the longest odd length
        // palindrome with center point as i
        low = i - 1;
        high = i + 1;
        while (low >= 0 && high < len && str[low] == str[high]) {
            --low;
            ++high;
        }
    
        // Move back to the last possible valid palindrom substring
        // as that will anyway be the longest from above loop
        ++low; --high;
        if (str[low] == str[high] && high - low + 1 > maxLength) {
            start = low;
            maxLength = high - low + 1;
        }
    }

    printf("Longest palindrome substring is: ");
    printSubStr(str, start, start + maxLength - 1);

    return maxLength;
}

// Driver program to test above functions
int main()
{
    char str[] = "character";
    printf("\nLength is: %d\n", longestPalSubstr(str));
    return 0;
}

//                                      C H A R A C T E R
/*
 
 
 
 
 
 
 
 */
