//
//  main.cpp
//  fibmodif
//
//  Created by Leonardo Alejandro González López on 25/10/21.
//  Copyright © 2021 UASLP. All rights reserved.
//

#include <iostream>
using namespace std;

// Find n term of the serie 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, ...


 long  fibmodf( int n);

int main()
{
//    for (int i = 0; i < 10; i++)
//        cout << fibmodf(i) << " ";
//    return 0;
    int n;
    cout << "Which number you want to know?\n";
    cin >> n;
    cout << fibmodf(n) << "\n";
}

 long  fibmodf( int n){
    
    long  x[n + 1];

     x[0] = 1;
     x[1] = 1;

    for (int i = 2; i <= n; i++) {
        x[i] = 0;
        for (int j = 0; j < i; j++)
            x[i] += x[j] * x[i - j - 1];
    }
    return x[n];
}
//
