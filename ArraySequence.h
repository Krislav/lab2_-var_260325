#pragma once
#include "Errors.h"
#include "DynamicArray.h"
#include "Sequence.h"
#include <iostream>

template <class T>
class ArraySequence : public Sequence<T> {
private:
    DynamicArray<T>* items;

public:
    ArraySequence(const T* items, int count) {
        this->items = new DynamicArray<T>(items, count);
    }

    ArraySequence() {
        items = new DynamicArray<T>(0);
    }

    ArraySequence (const ArraySequence<T>& other) {
        items = new DynamicArray<T>(*other.items);
    }

    virtual ~ArraySequence() {
        delete items;
    }

    virtual T GetFirst() const override {
        return items->Get(0);
    }

    virtual T GetLast() const override {
        return items->Get(items->GetSize() - 1);
    }

    virtual T Get(int index) const override {
        return items->Get(index);
    }

    virtual int GetLength() const override {
        return items->GetSize();
    }

    virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex) const override {
        if (startIndex < 0 || endIndex >= items->GetSize() || startIndex > endIndex) throw(ErrorCode::INDEX_OUT_OF_RANGE);
    
        int count = endIndex - startIndex + 1;
        T* sub_items = new T[count];
        for (int i = 0; i < count; ++i) {
            sub_items[i] = items->Get(startIndex + i);
        }
    
        ArraySequence<T>* res =  new ArraySequence<T>(sub_items, count);
        delete[] sub_items;
        return res;
    }

    virtual Sequence<T>* Append(const T& item) override {
        items->Resize(items->GetSize() + 1);
        items->Set(items->GetSize() - 1, item);
        return this;
    }

    virtual Sequence<T>* Prepend(const T& item) override {
        items->Resize(items->GetSize() + 1);
        for (int i = items->GetSize() - 1; i > 0; i--) {
            items->Set(i, items->Get(i - 1));
        }
        items->Set(0, item);
        return this;
    }

    virtual Sequence<T>* InsertAt(const T& item, int index) override {
        if (index < 0 || index > items->GetSize()) throw(ErrorCode::INDEX_OUT_OF_RANGE);
        items->Resize(items->GetSize() + 1);
        for (int i = items->GetSize() - 1; i > index; i--) {
            items->Set(i, items->Get(i - 1));
        }
        items->Set(index, item);
        return this;
    }

    virtual Sequence<T>* Concat(const Sequence<T>* list) const override {
        ArraySequence<T>* new_items = new ArraySequence<T>(*this);
        if (!list || list->GetLength() == 0) return new_items;
        for (int i = 0; i < list->GetLength(); i++) {
            new_items->Append(list->Get(i));
        }
        return new_items;
    }

    T& operator[](int index) {
        return (*items)[index];
    }

    const T& operator[](int index) const {
        return (*items)[index];
    }
};