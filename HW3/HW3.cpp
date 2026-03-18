// main

#include <iostream>
#include <string>


class Item
{
public:

	Item(const std::string& name, int price);

	const std::string& GetName() const;
	int GetPrice() const;
	void clear()
	{
		name_ = "";
		price_ = 0;
	}

private:
	std::string name_;
	int price_;
};


template<typename T>
class Inventory
{
public:
	Inventory(int capacity = 10)
	{
		capacity_ = (capacity <= 0) ? 1 : capacity;

		pItems_ = new T[capacity_];
	}

	~Inventory()
	{
		delete[] pItems_;

		pItems_ = nullptr;
	}

	void Additem(const T& item)
	{
		if (size_ >= capacity_)
		{
			std::cout << "인벤토리가 꽉 찼습니다!" << std::endl;
			return;
		}
		pItems_[size_] = item;
		size_++;
	}

	void Removelastitem()
	{
		if (size_ <= 0)
		{
			std::cout << "인벤토리가 비어있습니다." << std::endl;
			return;
		}
		size_--;
	}

	int Getsize() const
	{
		return size_;
	}

	int Getcapacity() const
	{
		return capacity_;
	}


	void Printallitems() const
	{
		for (int i = 0; i < size_; i++)
		{
			std::cout << "[이름: " << pItems_[i].GetName() << " 가격:" << pItems_[i].GetPrice() << std::endl;
		}
	}



private:
	T* pItems_;
	int capacity_;
	int size_;


};



void main(void)
{
	Inventory<Item>* iteminventory = new Inventory<Item>();
	for (int i = 0; i < 11; ++i)
	{
		iteminventory->Additem(Item("Item" + std::to_string(i), i * 100));
	}

	iteminventory->Printallitems();

	delete iteminventory;

}