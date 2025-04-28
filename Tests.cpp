#include "Tests.h"

void TestResultPrint(int result_of_test, int test_group_number, int test_number){
    switch (result_of_test)
    {
    case 0:
        std::cout << "Test " << test_group_number << "." << test_number << " passed [O]\n";
        break;
    case 1:
        std::cout << "Test " << test_group_number << "." << test_number << " failed [X]\n";
        break;
    case 2:
        std::cout << "Test " << test_group_number << "." << test_number << " ended with unexpected error [?]\n";
        break;
    default:
    std::cout << "Test " << test_group_number << "." << test_number << " uncorrect\n";
        break;
    }
}

void TestLinkedList() { //GROUP 1
    int test_group_number = 1;
    int test_number = 1;
    int result_of_test = 0;

    result_of_test = 0; //TEST 1.1
    LinkedList<int> list11;
    if (list11.GetLength() != 0) result_of_test = 1;
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 1.2
    try {
        list11.GetFirst();
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 1.3
    try {
        list11.GetLast();
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 1.4
    try {
        list11.Get(0);
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 1.5
    int data[5] = {0, 1, 2, 3, 4};
    LinkedList<int> list15(data, 5);
    try {
        for (int i = 0; i < 5; i++) {
            if (list15[i] != i) result_of_test = 1;
        }
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 1.6
    try {
        list15.Get(-1);
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 1.7
    try {
        list15.Get(5);
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 1.8
    LinkedList<int> list18(list15);
    try {
        for (int i = 0; i < 5; i++) {
            if (list18[i] != i) result_of_test = 1;
        }
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 1.9
    try {
        if (list15.GetFirst() != 0) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 1.10
    try {
        if (list15.GetLast() != 4) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 1.11
    try {
        if (list15.Get(2) != 2) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 1.12
    try {
        list15[-1];
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 1.13
    try {
        list15[5];
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 1.14
    try {
        if (list15.GetLength() != 5) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 1.15
    LinkedList<int> sub_list115(*(list15.GetSubList(1, 3)));
    try {
        for (int i = 0; i < 3; i++) {
            if (sub_list115[i] != i + 1) result_of_test = 1;
        }
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 1.16
    LinkedList<int> sub_list116(*(list15.GetSubList(0, 4)));
    try {
        for (int i = 0; i < 5; i++) {
            if (sub_list116[i] != i) result_of_test = 1;
        }
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 1.17
    LinkedList<int> sub_list117(*(list15.GetSubList(2, 2)));
    try {
       if (sub_list117[0] != 2) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 1.18
    try {
        LinkedList<int> sub_list118(*(list15.GetSubList(3, 2)));
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 1.19
    try {
        LinkedList<int> sub_list119(*(list15.GetSubList(-1, 2)));
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 1.20
    try {
        LinkedList<int> sub_list120(*(list15.GetSubList(1, 5)));
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 1.21
    try {
        list15.Append(5);
        if (list15[5] != 5) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 1.22
    LinkedList<int> list122(list15);
    try {
        list122.Prepend(-1);
        if (list122[0] != -1) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 1.23
    try {
        list122.InsertAt(10, 3);
        if (list122[3] != 10) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 1.24
    try {
        list122.InsertAt(10, 9);
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 1.25
    try {
        list122.InsertAt(10, -1);
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 1.26
    try {
        list122.InsertAt(11, 8);
        if (list122[8] != 11) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 1.27
    try {
        list122.InsertAt(12, 0);
        if (list122[0] != 12) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 1.28
    int data1[5] = {0, 1, 2, 3, 4};
    int data2[3] = {5, 6, 7};
    LinkedList<int> list128_1(data1, 5);
    LinkedList<int> list128_2(data2, 3);
    try {
        list128_1.Concat(&list128_2);
        if (list128_1.GetLength() != 8) result_of_test = 1;
        for (int i = 0; i < 8; i++) {
            if (list128_1[i] != i) result_of_test = 1;
        }        
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 1.29
    LinkedList<int> list129_1(data1, 5);
    LinkedList<int> list129_2;
    try {
        list129_1.Concat(&list129_2);
        if (list129_1.GetLength() != 5) result_of_test = 1;
        for (int i = 0; i < 5; i++) {
            if (list129_1[i] != i) result_of_test = 1;
        }
        if (list129_2.GetLength() != 0) result_of_test = 1;
        
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 1.30
    LinkedList<int> list130_1;
    LinkedList<int> list130_2(data1, 5);
    try {
        list130_1.Concat(&list130_2);
        if (list130_1.GetLength() != 5) result_of_test = 1;
        for (int i = 0; i < 5; i++) {
            if (list130_1[i] != i) result_of_test = 1;
        }        
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;
}

void TestDynamicArray() { //GROUP 2
    int test_group_number = 2;
    int test_number = 1;
    int result_of_test = 0;

    result_of_test = 0; //TEST 2.1
    DynamicArray<int> list21;
    if (list21.GetSize() != 0) result_of_test = 1;
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 2.2
    try {
        list21.Get(0);
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 2.3
    try {
        list21[0];
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 2.4
    try {
        list21.Set(0, 1);
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 2.5
    try {
        list21.Resize(-1);
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::NEGATIVE_QUANTITY) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 2.6
    try {
        list21.Resize(3);
        if (list21.GetSize() != 3) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 2.7
    try {
        for (int i = 0; i < 3; i++) {
            list21.Set(i, i);
        }
        for (int i = 0; i < 3; i++) {
            if (list21[i] != i) result_of_test = 1;
        }
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 2.8
    try {
        list21.Resize(2);
        if (list21.GetSize() != 2) result_of_test = 1;
        for (int i = 0; i < 2; i++) {
            if (list21[i] != i) result_of_test = 1;
        }
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 2.9
    DynamicArray<int> list29(5);
    try {
        if (list29.GetSize() != 5) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 2.10
    try {
        for (int i = 0; i < 5; i++) {
            list29.Set(i, i);
        }
        for (int i = 0; i < 5; i++) {
            if (list29[i] != i) result_of_test = 1;
        }
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 2.11
    int data[5] = {0, 1, 2, 3, 4};
    DynamicArray<int> list211(data, 5);
    try {
        if (list211.GetSize() != 5) result_of_test = 1;
        for (int i = 0; i < 5; i++) {
            if (list211[i] != i) result_of_test = 1;
        }
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 2.12
    try {
        DynamicArray<int> list212(data, -1);
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::NEGATIVE_QUANTITY) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 2.13
    try {
        DynamicArray<int> list213(-1);
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::NEGATIVE_QUANTITY) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 2.14
    DynamicArray<int> list214(list211);
    try {
        for (int i = 0; i < 5; i++) {
            if (list214[i] != i) result_of_test = 1;
        }
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 2.15
    try {
        list214.Set(3, 6);
        if (list214[3] != 6) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 2.16
    try {
        list214.Set(-1, 7);
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 2.17
    try {
        list214.Set(5, 7);
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 2.18
    try {
        if (list214.Get(1) != 1) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 2.19
    try {
        list214.Get(-1);
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 2.20
    try {
        list214.Get(5);
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;
}

void TestListSequence() { //GROUP 3
    int test_group_number = 3;
    int test_number = 1;
    int result_of_test = 0;

    result_of_test = 0; //TEST 3.1
    ListSequence<int> list31;
    try {
        if (list31.GetLength() != 0) result_of_test = 1;
    }
    catch (ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 3.2
    int data[5] = {0, 1, 2, 3, 4};
    ListSequence<int> list32(data, 5);
    try {
        if (list32.GetLength() != 5) result_of_test = 1;
        for (int i = 0; i < 5; i++) {
            if (list32[i] != i) result_of_test = 1;
        }
    }
    catch (ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 3.3
    ListSequence<int> list33(list32);
    try {
        if (list33.GetLength() != 5) result_of_test = 1;
        for (int i = 0; i < 5; i++) {
            if (list33[i] != i) result_of_test = 1;
        }
    }
    catch (ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 3.4
    try {
        list32[-1];
    }
    catch (ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 3.5
    try {
        list32[5];
    }
    catch (ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 3.6
    try {
        list31.GetFirst();
    }
    catch (ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 3.7
    try {
        list31.GetLast();
    }
    catch (ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 3.8
    try {
        if (list32.GetFirst() != 0) result_of_test = 1;
    }
    catch (ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 3.9
    try {
        if (list32.GetLast() != 4) result_of_test = 1;
    }
    catch (ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 3.10
    try {
        if (list32.Get(2) != 2) result_of_test = 1;
    }
    catch (ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 3.11
    try {
        list32.Get(-1);
    }
    catch (ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 3.12
    try {
        list32.Get(5);
    }
    catch (ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 3.13
    try {
        ListSequence<int>* sub_list313 = dynamic_cast<ListSequence<int>*>(list32.GetSubsequence(1, 3));
        for (int i = 0; i < 3; i++) {
            if ((*sub_list313)[i] != i + 1) result_of_test = 1;
        }
    }
    catch (ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 3.14
    try {
        ListSequence<int>* sub_list314 = dynamic_cast<ListSequence<int>*>(list32.GetSubsequence(3, 2));
    }
    catch (ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 3.15
    try {
        ListSequence<int>* sub_list315 = dynamic_cast<ListSequence<int>*>(list32.GetSubsequence(-1, 2));
    }
    catch (ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 3.16
    try {
        ListSequence<int>* sub_list316 = dynamic_cast<ListSequence<int>*>(list32.GetSubsequence(1, 5));
    }
    catch (ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 3.17
    ListSequence<int> list317(list32);
    try {
        list317.Append(5);
        if (list317[5] != 5) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 3.18
    ListSequence<int> list318(list32);
    try {
        list318.Prepend(-1);
        if (list318[0] != -1) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 3.19
    ListSequence<int> list319(list32);
    try {
        list319.InsertAt(10, 3);
        if (list319[3] != 10) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 3.20
    ListSequence<int> list320(list32);
    try {
        list320.InsertAt(10, 6);
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 3.21
    ListSequence<int> list321(list32);
    try {
        list321.InsertAt(10, -1);
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 3.22
    ListSequence<int> list322(list32);
    try {
        list322.InsertAt(11, 5);
        if (list322[5] != 11) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 3.23
    ListSequence<int> list323(list32);
    try {
        list323.InsertAt(12, 0);
        if (list323[0] != 12) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 3.24
    int data1[5] = {0, 1, 2, 3, 4};
    int data2[3] = {5, 6, 7};
    ListSequence<int> list324_1(data1, 5);
    ListSequence<int> list324_2(data2, 3);
    try {
        ListSequence<int>* list324_3 = dynamic_cast<ListSequence<int>*>(list324_1.Concat(&list324_2));
        if ((*list324_3).GetLength() != 8) result_of_test = 1;
        for (int i = 0; i < 8; i++) {
            if ((*list324_3)[i] != i) result_of_test = 1;
        }
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 3.25
    ListSequence<int> list325_1(data1, 5);
    ListSequence<int> list325_2;
    try {
        ListSequence<int>* list325_3 = dynamic_cast<ListSequence<int>*>(list325_1.Concat(&list325_2));
        if ((*list325_3).GetLength() != 5) result_of_test = 1;
        for (int i = 0; i < 5; i++) {
            if ((*list325_3)[i] != i) result_of_test = 1;
        }
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 3.26
    ListSequence<int> list326_1;
    ListSequence<int> list326_2(data1, 5);
    try {
        ListSequence<int>* list326_3 = dynamic_cast<ListSequence<int>*>(list326_1.Concat(&list326_2));
        if ((*list326_3).GetLength() != 5) result_of_test = 1;
        for (int i = 0; i < 5; i++) {
            if ((*list326_3)[i] != i) result_of_test = 1;
        }
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;
}

void TestArraySequence() { //GROUP 4
    int test_group_number = 4;
    int test_number = 1;
    int result_of_test = 0;

    result_of_test = 0; //TEST 4.1
    ArraySequence<int> list41;
    try {
        if (list41.GetLength() != 0) result_of_test = 1;
    }
    catch (ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 4.2
    int data[5] = {0, 1, 2, 3, 4};
    ArraySequence<int> list42(data, 5);
    try {
        if (list42.GetLength() != 5) result_of_test = 1;
        for (int i = 0; i < 5; i++) {
            if (list42[i] != i) result_of_test = 1;
        }
    }
    catch (ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 4.3
    ArraySequence<int> list43(list42);
    try {
        if (list43.GetLength() != 5) result_of_test = 1;
        for (int i = 0; i < 5; i++) {
            if (list43[i] != i) result_of_test = 1;
        }
    }
    catch (ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 4.4
    try {
        list42[-1];
    }
    catch (ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 4.5
    try {
        list42[5];
    }
    catch (ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 4.6
    try {
        list41.GetFirst();
    }
    catch (ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 4.7
    try {
        list41.GetLast();
    }
    catch (ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 4.8
    try {
        if (list42.GetFirst() != 0) result_of_test = 1;
    }
    catch (ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 4.9
    try {
        if (list42.GetLast() != 4) result_of_test = 1;
    }
    catch (ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 4.10
    try {
        if (list42.Get(2) != 2) result_of_test = 1;
    }
    catch (ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 4.11
    try {
        list42.Get(-1);
    }
    catch (ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 4.12
    try {
        list42.Get(5);
    }
    catch (ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 4.13
    try {
        ArraySequence<int>* sub_list413 = dynamic_cast<ArraySequence<int>*>(list42.GetSubsequence(1, 3));
        for (int i = 0; i < 3; i++) {
            if ((*sub_list413)[i] != i + 1) result_of_test = 1;
        }
    }
    catch (ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 4.14
    try {
        ArraySequence<int>* sub_list414 = dynamic_cast<ArraySequence<int>*>(list42.GetSubsequence(3, 2));
    }
    catch (ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 4.15
    try {
        ArraySequence<int>* sub_list415 = dynamic_cast<ArraySequence<int>*>(list42.GetSubsequence(-1, 2));
    }
    catch (ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 4.16
    try {
        ArraySequence<int>* sub_list416 = dynamic_cast<ArraySequence<int>*>(list42.GetSubsequence(1, 5));
    }
    catch (ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 4.17
    ArraySequence<int> list417(list42);
    try {
        list417.Append(5);
        if (list417[5] != 5) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 4.18
    ArraySequence<int> list418(list42);
    try {
        list418.Prepend(-1);
        if (list418[0] != -1) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 4.19
    ArraySequence<int> list419(list42);
    try {
        list419.InsertAt(10, 3);
        if (list419[3] != 10) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 4.20
    ArraySequence<int> list420(list42);
    try {
        list420.InsertAt(10, 6);
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 4.21
    ArraySequence<int> list421(list42);
    try {
        list421.InsertAt(10, -1);
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 4.22
    ArraySequence<int> list422(list42);
    try {
        list422.InsertAt(11, 5);
        if (list422[5] != 11) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 4.23
    ArraySequence<int> list423(list42);
    try {
        list423.InsertAt(12, 0);
        if (list423[0] != 12) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 4.24
    int data1[5] = {0, 1, 2, 3, 4};
    int data2[3] = {5, 6, 7};
    ArraySequence<int> list424_1(data1, 5);
    ArraySequence<int> list424_2(data2, 3);
    try {
        ArraySequence<int>* list424_3 = dynamic_cast<ArraySequence<int>*>(list424_1.Concat(&list424_2));
        if ((*list424_3).GetLength() != 8) result_of_test = 1;
        for (int i = 0; i < 8; i++) {
            if ((*list424_3)[i] != i) result_of_test = 1;
        }
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 4.25
    ArraySequence<int> list425_1(data1, 5);
    ArraySequence<int> list425_2;
    try {
        ArraySequence<int>* list425_3 = dynamic_cast<ArraySequence<int>*>(list425_1.Concat(&list425_2));
        if ((*list425_3).GetLength() != 5) result_of_test = 1;
        for (int i = 0; i < 5; i++) {
            if ((*list425_3)[i] != i) result_of_test = 1;
        }
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 4.26
    ArraySequence<int> list426_1;
    ArraySequence<int> list426_2(data1, 5);
    try {
        ArraySequence<int>* list426_3 = dynamic_cast<ArraySequence<int>*>(list426_1.Concat(&list426_2));
        if ((*list426_3).GetLength() != 5) result_of_test = 1;
        for (int i = 0; i < 5; i++) {
            if ((*list426_3)[i] != i) result_of_test = 1;
        }
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;
}

void TestImmutableListSequence() { //GROUP 5
    int test_group_number = 5;
    int test_number = 1;
    int result_of_test = 0;

    result_of_test = 0; //TEST 5.1
    ImmutableListSequence<int> list51;
    try {
        if (list51.GetLength() != 0) result_of_test = 1;
    }
    catch (ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 5.2
    int data[5] = {0, 1, 2, 3, 4};
    ImmutableListSequence<int> list52(data, 5);
    try {
        if (list52.GetLength() != 5) result_of_test = 1;
        for (int i = 0; i < 5; i++) {
            if (list52[i] != i) result_of_test = 1;
        }
    }
    catch (ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 5.3
    ImmutableListSequence<int> list53(list52);
    try {
        if (list53.GetLength() != 5) result_of_test = 1;
        for (int i = 0; i < 5; i++) {
            if (list53[i] != i) result_of_test = 1;
        }
    }
    catch (ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 5.4
    try {
        list52[-1];
    }
    catch (ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 5.5
    try {
        list52[5];
    }
    catch (ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 5.6
    try {
        list51.GetFirst();
    }
    catch (ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 5.7
    try {
        list51.GetLast();
    }
    catch (ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 5.8
    try {
        if (list52.GetFirst() != 0) result_of_test = 1;
    }
    catch (ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 5.9
    try {
        if (list52.GetLast() != 4) result_of_test = 1;
    }
    catch (ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 5.10
    try {
        if (list52.Get(2) != 2) result_of_test = 1;
    }
    catch (ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 5.11
    try {
        list52.Get(-1);
    }
    catch (ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 5.12
    try {
        list52.Get(5);
    }
    catch (ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 5.13
    try {
        ImmutableListSequence<int>* sub_list513 = dynamic_cast<ImmutableListSequence<int>*>(list52.GetSubsequence(1, 3));
        for (int i = 0; i < 3; i++) {
            if ((*sub_list513)[i] != i + 1) result_of_test = 1;
        }
    }
    catch (ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 5.14
    try {
        ImmutableListSequence<int>* sub_list514 = dynamic_cast<ImmutableListSequence<int>*>(list52.GetSubsequence(3, 2));
    }
    catch (ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 5.15
    try {
        ImmutableListSequence<int>* sub_list515 = dynamic_cast<ImmutableListSequence<int>*>(list52.GetSubsequence(-1, 2));
    }
    catch (ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 5.16
    try {
        ImmutableListSequence<int>* sub_list516 = dynamic_cast<ImmutableListSequence<int>*>(list52.GetSubsequence(1, 5));
    }
    catch (ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 5.17
    try {
        ImmutableListSequence<int>* list517 = dynamic_cast<ImmutableListSequence<int>*>(list52.Append(5));
        if ((*list517)[5] != 5) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 5.18
    try {
        ImmutableListSequence<int>* list518 = dynamic_cast<ImmutableListSequence<int>*>(list52.Prepend(-1));
        if ((*list518)[0] != -1) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 5.19
    try {
        ImmutableListSequence<int>* list519 = dynamic_cast<ImmutableListSequence<int>*>(list52.InsertAt(10, 3));
        if ((*list519)[3] != 10) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 5.20
    try {
        ImmutableListSequence<int>* list520 = dynamic_cast<ImmutableListSequence<int>*>(list52.InsertAt(10, 6));
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 5.21
    try {
        ImmutableListSequence<int>* list521 = dynamic_cast<ImmutableListSequence<int>*>(list52.InsertAt(10, -1));
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 5.22
    try {
        ImmutableListSequence<int>* list522 = dynamic_cast<ImmutableListSequence<int>*>(list52.InsertAt(11, 5));
        if ((*list522)[5] != 11) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 5.23
    try {
        ImmutableListSequence<int>* list523 = dynamic_cast<ImmutableListSequence<int>*>(list52.InsertAt(12, 0));
        if ((*list523)[0] != 12) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 5.24
    int data1[5] = {0, 1, 2, 3, 4};
    int data2[3] = {5, 6, 7};
    ImmutableListSequence<int> list524_1(data1, 5);
    ImmutableListSequence<int> list524_2(data2, 3);
    try {
        ImmutableListSequence<int>* list524_3 = dynamic_cast<ImmutableListSequence<int>*>(list524_1.Concat(&list524_2));
        if ((*list524_3).GetLength() != 8) result_of_test = 1;
        for (int i = 0; i < 8; i++) {
            if ((*list524_3)[i] != i) result_of_test = 1;
        }
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 5.25
    ImmutableListSequence<int> list525_1(data1, 5);
    ImmutableListSequence<int> list525_2;
    try {
        ImmutableListSequence<int>* list525_3 = dynamic_cast<ImmutableListSequence<int>*>(list525_1.Concat(&list525_2));
        if ((*list525_3).GetLength() != 5) result_of_test = 1;
        for (int i = 0; i < 5; i++) {
            if ((*list525_3)[i] != i) result_of_test = 1;
        }
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 5.26
    ImmutableListSequence<int> list526_1;
    ImmutableListSequence<int> list526_2(data1, 5);
    try {
        ImmutableListSequence<int>* list526_3 = dynamic_cast<ImmutableListSequence<int>*>(list526_1.Concat(&list526_2));
        if ((*list526_3).GetLength() != 5) result_of_test = 1;
        for (int i = 0; i < 5; i++) {
            if ((*list526_3)[i] != i) result_of_test = 1;
        }
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;
}

void TestImmutableArraySequence() { //GROUP 6
    int test_group_number = 6;
    int test_number = 1;
    int result_of_test = 0;

    result_of_test = 0; //TEST 6.1
    ImmutableArraySequence<int> list61;
    try {
        if (list61.GetLength() != 0) result_of_test = 1;
    }
    catch (ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 6.2
    int data[5] = {0, 1, 2, 3, 4};
    ImmutableArraySequence<int> list62(data, 5);
    try {
        if (list62.GetLength() != 5) result_of_test = 1;
        for (int i = 0; i < 5; i++) {
            if (list62[i] != i) result_of_test = 1;
        }
    }
    catch (ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 6.3
    ImmutableArraySequence<int> list63(list62);
    try {
        if (list63.GetLength() != 5) result_of_test = 1;
        for (int i = 0; i < 5; i++) {
            if (list63[i] != i) result_of_test = 1;
        }
    }
    catch (ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 6.4
    try {
        list62[-1];
    }
    catch (ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 6.5
    try {
        list62[5];
    }
    catch (ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 6.6
    try {
        list61.GetFirst();
    }
    catch (ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 6.7
    try {
        list61.GetLast();
    }
    catch (ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 6.8
    try {
        if (list62.GetFirst() != 0) result_of_test = 1;
    }
    catch (ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 6.9
    try {
        if (list62.GetLast() != 4) result_of_test = 1;
    }
    catch (ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 6.10
    try {
        if (list62.Get(2) != 2) result_of_test = 1;
    }
    catch (ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 6.11
    try {
        list62.Get(-1);
    }
    catch (ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 6.12
    try {
        list62.Get(5);
    }
    catch (ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 6.13
    try {
        ImmutableArraySequence<int>* sub_list613 = dynamic_cast<ImmutableArraySequence<int>*>(list62.GetSubsequence(1, 3));
        for (int i = 0; i < 3; i++) {
            if ((*sub_list613)[i] != i + 1) result_of_test = 1;
        }
    }
    catch (ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 6.14
    try {
        ImmutableArraySequence<int>* sub_list614 = dynamic_cast<ImmutableArraySequence<int>*>(list62.GetSubsequence(3, 2));
    }
    catch (ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 6.15
    try {
        ImmutableArraySequence<int>* sub_list615 = dynamic_cast<ImmutableArraySequence<int>*>(list62.GetSubsequence(-1, 2));
    }
    catch (ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 6.16
    try {
        ImmutableArraySequence<int>* sub_list616 = dynamic_cast<ImmutableArraySequence<int>*>(list62.GetSubsequence(1, 5));
    }
    catch (ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 6.17
    try {
        ImmutableArraySequence<int>* list617 = dynamic_cast<ImmutableArraySequence<int>*>(list62.Append(5));
        if ((*list617)[5] != 5) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 6.18
    try {
        ImmutableArraySequence<int>* list618 = dynamic_cast<ImmutableArraySequence<int>*>(list62.Prepend(-1));
        if ((*list618)[0] != -1) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 6.19
    try {
        ImmutableArraySequence<int>* list619 = dynamic_cast<ImmutableArraySequence<int>*>(list62.InsertAt(10, 3));
        if ((*list619)[3] != 10) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 6.20
    try {
        ImmutableArraySequence<int>* list620 = dynamic_cast<ImmutableArraySequence<int>*>(list62.InsertAt(10, 6));
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 6.21
    try {
        ImmutableArraySequence<int>* list621 = dynamic_cast<ImmutableArraySequence<int>*>(list62.InsertAt(10, -1));
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 6.22
    try {
        ImmutableArraySequence<int>* list622 = dynamic_cast<ImmutableArraySequence<int>*>(list62.InsertAt(11, 5));
        if ((*list622)[5] != 11) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 6.23
    try {
        ImmutableArraySequence<int>* list623 = dynamic_cast<ImmutableArraySequence<int>*>(list62.InsertAt(12, 0));
        if ((*list623)[0] != 12) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 6.24
    int data1[5] = {0, 1, 2, 3, 4};
    int data2[3] = {5, 6, 7};
    ImmutableArraySequence<int> list624_1(data1, 5);
    ImmutableArraySequence<int> list624_2(data2, 3);
    try {
        ImmutableArraySequence<int>* list624_3 = dynamic_cast<ImmutableArraySequence<int>*>(list624_1.Concat(&list624_2));
        if ((*list624_3).GetLength() != 8) result_of_test = 1;
        for (int i = 0; i < 8; i++) {
            if ((*list624_3)[i] != i) result_of_test = 1;
        }
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 6.25
    ImmutableArraySequence<int> list625_1(data1, 5);
    ImmutableArraySequence<int> list625_2;
    try {
        ImmutableArraySequence<int>* list625_3 = dynamic_cast<ImmutableArraySequence<int>*>(list625_1.Concat(&list625_2));
        if ((*list625_3).GetLength() != 5) result_of_test = 1;
        for (int i = 0; i < 5; i++) {
            if ((*list625_3)[i] != i) result_of_test = 1;
        }
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 6.26
    ImmutableArraySequence<int> list626_1;
    ImmutableArraySequence<int> list626_2(data1, 5);
    try {
        ImmutableArraySequence<int>* list626_3 = dynamic_cast<ImmutableArraySequence<int>*>(list626_1.Concat(&list626_2));
        if ((*list626_3).GetLength() != 5) result_of_test = 1;
        for (int i = 0; i < 5; i++) {
            if ((*list626_3)[i] != i) result_of_test = 1;
        }
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;
}

void TestAll() {
    TestLinkedList();
    TestDynamicArray();
    TestListSequence();
    TestArraySequence();
    TestImmutableListSequence();
    TestImmutableArraySequence();
}