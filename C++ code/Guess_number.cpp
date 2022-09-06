// #include <iostream>
// #include <array>
// #include <ctime>
// #include <cstdlib>

// using namespace std;

// bool judInput(string &guess);
// bool judWin(string &guess, string &ans);
// void generator(string &ans);

// int main()
// {

//     string ans = "xxxx", guess;
//     bool jud = true;

//     srand(time(0));

//     generator(ans);

//     while (true)
//     {
//         if (jud)
//         {
//             cout << "A Player guess(4 four digits integer (no repeat)): ";
//         }
//         else
//         {
//             cout << "B Player guess(4 four digits integer (no repeat)): ";
//         }
//         cin >> guess;
//         if (judInput(guess))
//         {
//             cout << "input again !" << endl;
//             continue;
//         }
//         if (judWin(guess, ans))
//         {
//             if (jud)
//             {
//                 cout << "A player win !, answer is: " + ans << endl;
//             }
//             else
//             {
//                 cout << "B player win !, answer is: " + ans << endl;
//             }
//             return 0;
//         }
//         jud = !jud;
//     }
// }
// bool judInput(string &guess)
// {
//     if (guess.length() != 4)
//     {
//         return true;
//     }
//     for (int i = 0; i < 4; i++)
//     {
//         if (!(guess.at(i) <= '9' && guess.at(i) >= '0'))
//         {
//             return true;
//         }
//     }
//     for (int i = 0; i < 10; i++)
//     {
//         int count = 0;

//         for (int j = 0; j < 4; j++)
//         {
//             if ((char)(i + '0') == guess.at(j))
//             {
//                 count++;
//             }
//             if (count > 1)
//             {
//                 return true;
//             }
//         }
//     }
//     return false;
// }
// bool judWin(string &guess, string &ans)
// {
//     int x, y;

//     x = y = 0;

//     for (int i = 0; i < 4; i++)
//     {
//         if (ans.at(i) == guess.at(i))
//         {
//             x++;
//             guess.at(i) = 'x';
//         }
//     }
//     if (x == 4)
//     {
//         cout << "prompt: " << x << "A" << y << "B" << endl;
//         return true;
//     }
//     for (int i = 0; i < 4; i++)
//     {
//         for (int j = 0; j < 4; j++)
//         {
//             if (ans.at(j) == guess.at(i))
//             {
//                 y++;
//             }
//         }
//     }
//     cout << "prompt: " << x << "A" << y << "B" << endl;
//     return false;
// }
// void generator(string &ans)
// {
//     array<bool, 10> number;
//     int temp;

//     number.fill(false);

//     for (int i = 0; i < 4; i++)
//     {
//         temp = rand() % 10;

//         if (number.at(temp) == true)
//         {
//             i--;
//             continue;
//         }
//         number.at(temp) = true;
//         ans.at(i) = (char)((int)'0' + temp);
//     }
// }