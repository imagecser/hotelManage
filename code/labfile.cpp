#include "labfile.h"

fstream & fio::finput() {
	stringstream ss, ps;
	f.open(hotelLoc, ios::in);
	while (f) {
		Hotel *h = new Hotel;
		string line, sIndex;
		getline(f, line); 
		if (line.size() == 0) break;
		ss << line; // ��һ������ss����
		getline(ss, sIndex, ','); 
		ps << sIndex; 
		ps >> h->indexH; 
		ps.clear(); // ���׸�index�ַ���ת��Ϊ����
		getline(ss, h->name, ','); 
		getline(ss, h->city, ','); 
		getline(ss, h->area, '|'); // ���hotelʵ��������
		vector<Room> *pvecr = new vector<Room>;
		while (true) {
			Room *r = new Room;
			r->photel = h;
			getline(ss, sIndex, ',');
			if (sIndex.size() == 0) break; // �жϵ�ͷ���
			ps << sIndex; 
			ps >> r->numR; ps.clear(); // ���׸�numR�ַ���ת��Ϊ����
			getline(ss, sIndex, ','); 
			ps << sIndex; 
			ps >> r->price; 
			ps.clear(); // ���׸�price�ַ���ת��Ϊ����
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

fstream & fio::odinput() {
	f.open("order.txt", ios::in);
	stringstream ss, ps;
	while(f) {
		Order *od = new Order;
		string line, sIndex;
		getline(f, line);
		if(line.size() == 0) break;
		ss << line;
		getline(ss, sIndex, '|');
		ps << sIndex; ps >> od->orderIndex; ps.clear();
		int indexag, numarg;
		string namearg, cityarg, areaarg;
		getline(ss, sIndex, ',');
		ps << sIndex; ps >> indexag; ps.clear();
		getline(ss, namearg, ',');
		getline(ss, cityarg, ',');
		getline(ss, areaarg, ',');
		getline(ss, sIndex, '|');
		ps << sIndex; ps >> numarg; ps.clear();
		for (auto &outitem:vrooms)
			for (auto &initem : outitem) {
				if (indexag == initem.photel->indexH && namearg == initem.photel->name &&
					cityarg == initem.photel->city && areaarg == initem.photel->area && 
					numarg == initem.numR) {
					od->proom = &initem;
					break;
				}
			}
		string pstr[6];
		for (int i = 0; i < 6; ++i) {
			getline(ss, pstr[i], '/');
			ps << pstr[i]; ps >> od->date[i]; ps.clear();
		}
		getline(ss, od->uname, '|');
		getline(ss, od->idcard, '|');
		vorders.push_back(*od);
	}
	f.close();
	// TODO: ����order.txt�ļ�
	return f;
}

fstream & fio::odsave() {
	f.open("orderx.txt", ios::out);
	cout << vorders.size();
	for (auto item : vorders) {
		f << setfill('0') << setw(6) << item.orderIndex;
		f << '|' << setfill('0') << setw(4) <<item.proom->photel->indexH;
		f << ',' << item.proom->photel->name << ',' << item.proom->photel->city << ',' << item.proom->photel->area << item.proom->numR << '|';
		for (int i = 0; i < 6; ++i) f << item.date[i] << '/';
		f << item.uname << '|' << item.idcard << '|';
		f << endl;
	}
	f.close();
	return f;
	// TODO: �洢vorders��order.txt
}
