//
// Created by whp98 on 2020/1/2.
//

#include<iostream>
#include<algorithm>

using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

/*������a��ֵ����ʹ��Ԫ�صķֲ����м����������μ���*/
void strageSort(int n, int a[]) {
    int i, k, mid;
    sort(a, a + n, cmp);
    mid = n / 2;
    int b[n + 1];
    b[mid] = a[0];
    for (i = 1, k = 1; i < n; i++, k++) { //����a��ֵ�ֲ����м����������μ���
        b[mid - k] = a[i];
        i++;
        if (i != n)
            b[mid + k] = a[i];
    }
    for (int i = 0; i < n; i++) {     //���仯���a����
        a[i] = b[i];
    }
}

void minStorage(int n, int a[]) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    double result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) { //�Ӵŵ�0-n-1���������ǵĴŵ���ļ���ʱ��
            result += (a[i] * 1.0 / sum) * (a[j] * 1.0 / sum) * (j - i);
        }
    }

    cout << "��С��������ʱ��:" << result << endl;


    printf("���");

}

int main() {
    int n, k, mid, i;

    FILE *fpRead = fopen("input.txt", "r");
    fscanf(fpRead, "%d ", &n);
    int a[n + 1];
    for (int i = 0; i < n; i++) {
        fscanf(fpRead, "%d ", &a[i]);
    }
    strageSort(n, a);
    minStorage(n, a);
    return 0;
}

