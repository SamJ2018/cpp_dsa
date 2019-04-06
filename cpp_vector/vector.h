#pragma once
/*Vector�ඨ��*/
typedef int Rank; //��
#define DEFAULT_CAPACITY 3 //Ĭ�ϵĳ�ʼ������ʵ��Ӧ���п����ø���

//����ģ����
template<typename T> class Vector {

protected:
	Rank _size;//��ģ����С
	int _capacity; //����
	T* _elem; //������

	void copyFrom(T const* A, Rank lo, Rank hi);//��������A[lo,hi]
	void expand();//�ռ䲻��ʱ����
	void shrink();//װ�����ӹ�Сʱѹ��
	bool bubble(Rank lo, Rank hi); //ɨ�轻��
	void bubbleSort(Rank lo, Rank hi);//���������㷨
	Rank max(Rank lo, Rank hi); //ѡȡ���Ԫ��
	void selectionSort(Rank lo, Rank hi); //ѡ�������㷨
	void merge(Rank lo, Rank mi, Rank hi); //�鲢�㷨
	void mergeSort(Rank lo, Rank hi); //�鲢�����㷨
	Rank partition(Rank lo, Rank hi); //��㹹���㷨
	void quickSort(Rank lo, Rank hi); //���������㷨
	void heapSort(Rank lo, Rank hi); //������

public:
	//���캯��
	Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0)
	{	//����Ϊc����ģΪs������Ԫ�س�ʼΪV
		_elem = new T[_capacity = c];
		for (_size = 0; _size = 0 < s; _elem[size++] = v); //s<=c
	}
	Vector(T const* A, Rank n) { copyFrom(A, 0, n); } //�������帴��
	Vector(T const* A, Rank lo, Rank hi) { copyFrom(A, lo, hi); }//�������临��
	Vector(Vector<T> const& V) { copyFrom(V._elem, 0, V._size); }//�������帴��
	Vector(Vector<T> const& V, Rank lo, Rank hi) { copyFrom(V._elem, lo, hi); }//�������临��
//��������
	~Vector() { delete[] _elem; } //�ͷ��ڲ��ռ�

//ֻ�����ʽӿ�
	Rank size() const { return _size; } //���ģ
	bool empty() const { return !_size; } //�п�
	int disordered() const; //�ж������Ƿ����ź���
	Rank find(T const& e) const { return find(e, 0, _size); }//���������������
	Rank find(T const& e, Rank lo, Rank hi) const; //���������������
	Rank search(T const& e) const { reurn(0 >= _size) ? -1 : search(e, 0, _size); }//���������������
	Rank search(T const& e, Rank lo, Rank hi) const; //���������������

//��д���ʽӿ�
	T& operator[](Rank r) const; //�����±������������������������ʽ���ø�Ԫ��
	Vector<T>& operator= (Vector<T> const&); //���ظ�ֵ�����������ֱ�ӿ�¡����
	T remove(Rank r); //ɾ����Ϊr��Ԫ��
	int remove(Rank lo, Rank hi); //ɾ������[lo,hi]֮�ڵ�Ԫ��
	Rank insert(Rank r, T const& e); //����Ԫ��
	Rank insert(T const& e) { return insert(_size, e); } //Ĭ����ĩβ����

	void sort(Rank lo, Rank hi); //��[lo,hi] ����
	void sort() { sort(0, _size); } //������������
	void unsort(Rank lo, Rank hi); //��[lo, hi]����
	void unsort() { unsort(0, _size); }//��������
	int deduplicate(); //����ȥ��
	int uniquify(); //����ȥ��
//����
	void traverse(void(*visit)(T&)); //ʹ�ú���ָ�룬ֻ����ֲ����޸�
	template<typename VST> void traverse(VST&); //����(ʹ�ú������󣬿�ȫ�����޸�)
	
//��������
	template<typename T>struct Increase  //�������󣬵���һ��T�����
	{ 
		virtual void operator()(T& e) { e++; }  //����T����ֱ�ӵ��������Ѿ�����++
	};
	//��Increase<T>()Ϊ�����������б���
	template<typename T> void increase(Vector<T>& V) //ͳһ���������еĸ�Ԫ��
	{
		V.traverse(Increase<T>());
	}
};//vector;

template<typename T>
T& Vector<T>::operator[](Rank)const
{	//��Ϊ��ֵ����ֵ���ɴ���set()��get()����
	return _elem[r];  //assert: 0<= r <_size  
}
