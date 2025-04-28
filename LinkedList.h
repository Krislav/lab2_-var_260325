#pragma once
#include "Errors.h"
#include <iostream>

template <class T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next_node;
        Node(const T& new_data) : data(new_data), next_node(nullptr) {}
    };
    Node* head;
    Node* tail;
    int size;
public:
    LinkedList() {
        head = tail = nullptr;
        size = 0;
    }

    LinkedList (const T* items, int count) : LinkedList() {
        if (count < 0) throw(ErrorCode::NEGATIVE_QUANTITY);
        for (int i = 0; i < count; i++) {
            Append(items[i]);
        }
    }

    LinkedList(const LinkedList<T>& other) : LinkedList() {
        Node* current = other.head;
        while (current) {
            Append(current->data);
            current = current->next_node;
        }
    }

    ~LinkedList() {
        Node* current = head;
        while (current) {
            Node* temp = current;
            current = current->next_node;
            delete temp;
        }
        head = tail = nullptr;
        size = 0;
    }

    T GetFirst() {
        if (size == 0) throw(ErrorCode::INDEX_OUT_OF_RANGE);
        return head->data;
    }

    T GetLast() {
        if (size == 0) throw(ErrorCode::INDEX_OUT_OF_RANGE);
        return tail->data;
    }

    T Get(int index) {
        if (index < 0 || index >= size) throw(ErrorCode::INDEX_OUT_OF_RANGE);
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next_node;
        }
        return current->data;
    }

    T& GetRef(int index) {
        if (index < 0 || index >= size) throw(ErrorCode::INDEX_OUT_OF_RANGE);
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next_node;
        }
        return current->data;
    }

    const T& GetRef(int index) const {
        if (index < 0 || index >= size) throw(ErrorCode::INDEX_OUT_OF_RANGE);
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next_node;
        }
        return current->data;
    }

    int GetLength() {
        return size;
    }

    LinkedList<T>* GetSubList(int startIndex, int endIndex) {
        if (startIndex < 0 || endIndex >= size || startIndex > endIndex) throw(ErrorCode::INDEX_OUT_OF_RANGE);
        LinkedList<T>* sub_list = new LinkedList<T>();
        Node* current = head;
        for (int i = 0; i < startIndex; i++) {
            current = current->next_node;
        }
        for (int i = startIndex; i <= endIndex; i++) {
            sub_list->Append(current->data);
            current = current->next_node;
        }
        return sub_list;
    }


    void Append(const T& item) {
        Node* new_node = new Node(item);
        if (new_node == nullptr) throw(ErrorCode::MEMORY_ALLOCATION_FAILED);
        if (size == 0) {
            head = tail = new_node;
        }
        else {
            tail->next_node = new_node;
            tail = new_node;    
        }
        size++;
    }

    void Prepend(const T& item) {
        Node* new_node = new Node(item);
        if (new_node == nullptr) throw(ErrorCode::MEMORY_ALLOCATION_FAILED);
        if (size == 0) {
            head = tail = new_node;
        }
        else {
            new_node->next_node = head;
            head = new_node;    
        }
        size++;
    }

    void InsertAt(const T& item, int index) {
        if (index < 0 || index > size) throw(ErrorCode::INDEX_OUT_OF_RANGE);
        if (index == 0) Prepend(item);
        else if (index == size) Append(item);
        else {
            Node* new_node = new Node(item);
            if (new_node == nullptr) throw(ErrorCode::MEMORY_ALLOCATION_FAILED);
            
            Node* current = head;
            for (int i = 0; i < index-1; i ++) current = current->next_node;
            new_node->next_node = current->next_node;
            current->next_node = new_node;
        }
        size++;
    }

    LinkedList<T>* Concat(const LinkedList<T> *list) {
        if (!list || list->size == 0) {
            return this;
        }
        LinkedList<T> new_list(*list);
        if (this->size == 0) {
            this->head = new_list.head;
            this->tail = new_list.tail;
            this->size = new_list.size;
        }
        else {
            this->tail->next_node = new_list.head;
            this->tail = new_list.tail;
            this->size += new_list.size;
        }
        return this;
    }

    T& operator[](int index) {
        if (index < 0 || index >= size) throw(ErrorCode::INDEX_OUT_OF_RANGE);
        return GetRef(index);
    }

    const T& operator[](int index) const {
        if (index < 0 || index >= size) throw(ErrorCode::INDEX_OUT_OF_RANGE);
        return GetRef(index);
    }
};