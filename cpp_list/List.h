/*�б�(list)�ṹ����ҲҪ���Ԫ�����߼��Ͼ������Դ��򣬵��������ַȴδ���κ�����--��̬�洢����*/

/*�б�ADT  ֧�ֽӿ�*/
/*************************************************************************************
�����ӿ�							����                                   ʹ�ö���
size()						����б�ǰ�Ĺ�ģ(��Ϊ�ڵ�����)				�б�
fist()						�����׽ڵ�λ��								�б�
last()						����β�ڵ�λ��								�б�
insertAsFirst(e)			��e�����׽ڵ����                            �б�
insertAsLast(e)             ��e����β�ڵ����                            �б�
insertBefore(p,e)           ��e�����ڵ�p��ֱ��ǰ��                        �б�
insertAfter(p,e)            ��e�����ڵ�p��ֱ�Ӻ��	                    �б�
remove(p)	                ɾ��λ��p���Ľڵ㣬����������ֵ                �б�
disordered()                �ж����нڵ��Ƿ��Ѱ��ǽ�������                 �б�
sort()                      �������ڵ�λ�ã�ʹ֮���ǽ�������               �б�
find(e)		                ����Ŀ��Ԫ��e,ʧ��ʱ����NULL                  �б�
search(e)                   ����Ŀ��Ԫ��e,���ز�����e�������Ľڵ�       �����б�
deduplicate()               ɾ���ظ��ڵ�                                 �б�
uniquify()                  ɾ���ظ����                                �����б�
traverse()                  ������ͳһ�������нڵ㣬�������ɺ�������ָ��   �б�
**********************************************************************************/

#include "ListNode.h"  //�����б�����

template<typename T> class List
{
	//�б�ģ����

private:
	int _size; //�ڵ��ģ
	ListNodePosi(T) header;   //ͷ�ڱ�������ͷ�ڵ�
	ListNodePosi(T) trailer;  //β�ڱ�

protected:
	void init();  //�б���ʱ�ĳ�ʼ��
	int clear();  //������нڵ�
	void copyNodes(ListNodePosi(T) p, int n);  //�����б�����λ��p���n��
	void merge(ListNodePosi(T)&, int); //�Ӷ�p��ʼ������n���ڵ�鲢����
	void mergeSort(ListNodePosi(T)&, int); //�Դ�p��ʼ������n���ڵ�鲢����
	void selectionSort(ListNodePosi(T), int); //�Դ�p��ʼ����n���ڵ�ѡ������
	void insertionSort(ListNodePosi(T), int); //�Ӷ�p��ʼ������n���ڵ��������

public:
//���캯��
	List() { init(); } //Ĭ�Ϲ���
	List(List<T> const& L); //���帳ֵ�б�L
	List(List<T> const& L, Rank r, int n); //�����б�L���Ե�r�����n��
	List(ListNodePosi(T) p, int n); //�����б�����λ��p���n��

//��������
	~List();  //�ͷţ�����ͷ��β�ڱ����ڵ� ���нڵ�

//ֻ�����ʽӿ�
	Rank size()const { return _size; } //���ģ
	bool empty()const { return _size <= 0; } //�п�
	T& operator[](Rank r) const;  //���أ�֧��ѭ�ȷ��ʣ���Ч�ʵ�
	ListNodePosi(T) first() const { return header->succ; }  //�����׽ڵ�λ��
	ListNodePosi(T) last() const { return trailer->pred; } //����β�ڵ�λ��

	bool valid(ListNodePosi(T) p) //�ж�λ��p�Ƿ����Ϸ�
	{
		return p && (trailer != p) && (header != p);  //��ͷ��β�ڵ��ͬ��NULL�������ɷ���
	}

	int disordered() const; //�ж��б��Ƿ��Ѿ�����
	//�����������
	ListNodePosi(T) find(T const& e, int n, ListNodePosi(T) p) const; 
	ListNodePosi(T) find(T const& e)const //�����б���ң��Ӻ���ǰ��
	{
		return find(e, _size, trailer);
	}

	//�����������
	ListNodePosi(T) search(T const& e, int n, ListNodePosi(T) p) const; 

	//�����б����
	ListNodePosi(T) search(T const& e) const
	{
		return search(e, _size, trailer);
	}

	//��p����ǰn-1�������ѡ�������
	ListNodePosi(T) selectMax(ListNodePosi(T) p, int n);
	//���������
	ListNodePosi(T) selectMax() { return selectMax(header->succ, _size); } 

//��д���ʽӿ�
	/*�������*/
	ListNodePosi(T) insertAsFirst(T const& e); //��e�����׽ڵ����
	ListNodePosi(T) insertAsLast(T const& e); //��e����β�ڵ����
	ListNodePosi(T) insertBefore(ListNodePosi(T) p, T const& e); //��e����p��ǰ������
	ListNodePosi(T) insertAfter(ListNodePosi(T) p, T const& e);  //��e����p�ĺ�̲���

	/*ɾ������*/
	T remove(ListNodePosi(T) p); //ɾ���Ϸ�λ��p���Ľڵ㣬���ر�ɾ���ڵ�

	void merge(List<T>& L) { merge(first(), _size, L, L.first, L._size); } //ȫ�б�鲢
	void sort(ListNodePosi(T) p, int n); //�б���������
	void sort() { sort(first(), _size); } //�б���������

	int deduplicate();  //����ȥ��
	int uniquify(); //����ȥ��
	void reverse(); //ǰ����

	//����
	void traverse(void(*visit)(T&)); //����������ʵʩvisit����������ָ�룬ֻ����ֲ����޸ģ�
	template<typename VST> void traverse(VST&); //����������ʵʩvisit�������������󣬿�ȫ���޸ģ�
}; //List�б�

