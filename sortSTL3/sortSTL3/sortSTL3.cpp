//���� ��ȸ���� ���� �ϳ��� Ǯ�� ���� Ŭ������ �����ϰ� �ִ� ���� ����ġ ����
//�ǹ����� ���� ��
//��ȸ���� ���(Pair) ���̺귯���� �����

#include <iostream>
#include <vector> //�ܼ��迭, ���Ḯ��Ʈ ��� vector 
#include <algorithm>

using namespace std;

int main(void) {
	vector<pair<int, string> > v;
	v.push_back(pair<int, string>(90, "����û"));
	v.push_back(pair<int, string>(65, "������"));
	v.push_back(pair<int, string>(87, "������"));
	v.push_back(pair<int, string>(88, "������"));
	v.push_back(pair<int, string>(60, "�ڿ���"));

	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].second << ' ';
	}
}
