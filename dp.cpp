# include <iostream>
# include <string>
# include <bits/stdc++.h>

using namespace std;

// // Deko bhai, pehle toh ek recursive function likh lo, using brut force to solve the problem, test ki sahi h for small input.
// int fact(int x){
//     if (x <=1)              // A stop criteria
//         return 1;

//     return x * fact(x - 1); // What needs to be done
// }

// Note: The below approach we used is called top down approach, were we started from the end results, and drew down the start.
//       We could had also used bottom up approach, were we start from smallest and store values till we reach n. It's generally implemented through iteration.

// Ab second step h ki bs 2 lines add kr do. (actually total 3 kehlai)
// vector<int> values(x); // We need a vector of size x(our value) or we can use a vector of max value of input possible
int fact(int x, vector<int>& values) // We can create it a global variable to avoid writting it like that, but it makes no difference
{
    if (values[x] != -1) return values[x]; // FIRST CHANGE // remember not to have n-1, as this would multiply zero too
    if (x <= 1) // A stop criteria
        return 1;

    return values[x] = (x * fact(x - 1, values)); // SECOND CHANGE: assigning and returning the values.
}
// Above 2 line of change, decreased the time complexity by huge difference.
// sirf n times hi calculations hongi, fir return hone lagegi constant time me values.
// Time complexity becomes2^k
// For fabonacci series, we can decrease time complexity to O(n*k) which worse can be O(n^2) which is way better than 2^n(expo)

int fact_bottom_up(int x, vector<int>& values){
    values[0] = 1;
    for (int i = 1; i<=x; i++) { // In this case, needs to start form 1, generally starts from where the second value can come from
        values[i] = i * values[i - 1];
    }
    return values[x];
}

int main()
{
    // Dynamic programming: hoooo...very very dangerous right? Wrong idiot! It's a ducking fuddu topic
    // DP bs recursion h jisko apan ne ek note book de di h, ki le bhai, ispe likh lena cheeze, taaki same cheez baar baar calculate mai time
    // waste na kare vo. Assume factorial of 10 is x. now I ask you factorial of 11, you know that its 11x10x9....... But why to calculate
    // it whole till one, simce you already have the value of 10!, just multiply it with 11 and you will have the answer.
    // This is what dp is all about, storing the info in a separate memory to save the time doing same work.
    // Dosen't it require O(n) memory? yes it does, even more than that based on how many changing variables are present(called states)
    // But for us, time is more important than memory, bs using extra memory it shows a great decrease in time complexity.
    // Generally it decreases the time complexity from as big as O(2^n) {exponential} to polynomial O(n^k), k>=0.
    // Also in case of factorial, O(n!) which is huge to O(2^n) which is way better.
    // Storing the info in called memoisation.

    // Apan jaane anjaane mai dp kai jagah use krte aaye h, jaise even in graphs traversal, by using a visited array, we save time from remembering
    // which array is already visited and we can even track the values. (Removing edge waale djs mai apan ne dp hi toh use kia tha, by storing
    // and comparing minimum difference). Dp is just a little more systmatic.

    // Gyaan toh bahut pel liya, but karna kaise h?
    // Uske liye, top pe jao
    
    // Now, important things, our array which will store the values. 
    // IT MUST BE INITITALIZED WITH A VALUES THAT CAN NEVER BE A REAL VALUES IN OUR ARRAY
    vector<int> values(16, -1); // Needs to create one extra for indexatio
    // memset(values, -1, 26*sizeof(int)); // We can use this to set default value in array, but remember, it only work for -1, simply use a for loop otherwise 
    cout<<"factorial of 10 is: "<< fact(10, values)<< endl; 
    // For bigger values, we need to set array to long long, this would be a thing in dp, as it deals with large values.
    cout << "factorial of 10 is: " << fact_bottom_up(10, values) << endl;

    return 0;
}