#include "labfile.h"

fstream & fio::finput() {
	stringstream ss, ps;
	f.open(hotelLoc, ios::in);
	for (int i = 0; f; ++i) {
		Hotel *h = new Hotel;
		string line, sIndex;
		getline(f, line); 
		if (line.size() == 0) break;
		ss << line; // ��һ������ss����
		getline(ss, sIndex, ','); ps << sIndex; ps >> h->indexH; ps.clear(); // ���׸�index�ַ���ת��Ϊ����
		getline(ss, h->name, ','); getline(ss, h->city, ','); getline(ss, h->area, '|'); // ���hotelʵ��������
		vector<Room> *pvecr = new vector<Room>;
		while (true) {
			Room *r = new Room;
			*r = *h;
			getline(ss, sIndex, ',');
			if (sIndex.size() == 0) break; // �жϵ�ͷ���
			ps << sIndex; ps >> r->numR; ps.clear(); // ���׸�numR�ַ���ת��Ϊ����
			getline(ss, sIndex, ','); ps << sIndex; ps >> r->price; ps.clear(); // ���׸�price�ַ���ת��Ϊ����
			getline(ss, r->type, '|'); // ���roomʵ��������
			pvecr->push_back(*r);
		}
		ss.clear();
		vrooms.push_back(*pvecr);
		vhotels.push_back(*h);
	}
	f.close();
	return f;
	// TODO: ��hotelLoc���뵽���ݽṹ
}

fstream & fio::fsave() {
	f.open(hotelLoc, ios::out);
	cout << vrooms.size() << endl << vhotels.size();
	for (unsigned int i = 0; i < vhotels.size(); ++i) {
		f << setfill('0') << setw(4) << vhotels[i].indexH;
		f << ',' << vhotels[i].name << ',' << vhotels[i].city << ',' << vhotels[i].area << '|';
		for (unsigned int j = 0; j < vrooms[i].size(); ++j) 
			f << vrooms[i][j].numR << ',' << vrooms[i][j].price << ',' << vrooms[i][j].type << '|';
		f << endl;
	}
	f.close();
	return f;
	// �洢���ݽṹ��hotelLoc
}
