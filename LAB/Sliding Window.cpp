#include <bits/stdc++.h>

using namespace std;
int frames[50];

void receiver(int s, int f)
{
    int i = (rand() % f);
    for (i; i <= f; i++)
    {
        if (i % s == 0)
        {
            cout << frames[i] << "\n";
            cout << "Acknowledgement of above frames sent is received by sender\n\n";
        }
        else
        {
            cout << frames[i] << " ";
        }
    }

    if (f % s != 0)
        cout << "\nAcknowledgement of above frames sent is received by sender\n";
}

void sender(int s, int f, int i)
{
    cout << "\nEnter " << f << " frames: ";
    for (i = 1; i <= f; i++)
    {
        cin >> frames[i];
    }
    receiver(s, f);
}

int main()
{
    int s, i, f;

    cout << "Enter window size: ";
    cin >> s;

    cout << "\nEnter number of frames to transmit: ";
    cin >> f;

    sender(s, f, i);

    return 0;
}

