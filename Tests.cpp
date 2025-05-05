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

    result_of_test = 0; //TEST 1.1 проверка создание пустого листа
    LinkedList<int> list11;
    if (list11.GetLength() != 0) result_of_test = 1;
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 1.2 проаерка возврата ошибок GetFirst
    try {
        list11.GetFirst();
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 1.3 проаерка возврата ошибок GetLast
    try {
        list11.GetLast();
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 1.4 проаерка возврата ошибок Get
    try {
        list11.Get(0);
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 1.5 проверка создания списка с элементами
    int out_data1[5] = {0, 1, 2, 3, 4};
    int data[5] = {0, 1, 2, 3, 4};
    LinkedList<int> out_list1(out_data1, 5);
    LinkedList<int> list15(data, 5);
    try {
        if (list15 != out_list1) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 1.6 проаерка возврата ошибок Get
    try {
        list15.Get(-1);
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 1.7 проаерка возврата ошибок Get
    try {
        list15.Get(5);
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 1.8  проаерка копирования списка
    LinkedList<int> list18(list15);
    try {
        if (list18 != out_list1) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 1.9 Проверка правильного возврата GetFirst
    try {
        if (list15.GetFirst() != 0) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 1.10 Проверка правильного возврата GetLast
    try {
        if (list15.GetLast() != 4) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 1.11  Проверка правильного возврата Get
    try {
        if (list15.Get(2) != 2) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 1.12 Проверка возврата ошибок []
    try {
        list15[-1];
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 1.13 Проверка возврата ошибок []
    try {
        list15[5];
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 1.14 Проверка GetLength
    try {
        if (list15.GetLength() != 5) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 1.15 Проверка правильности создания подсписка
    int out_data2[3] = {1, 2, 3};
    LinkedList<int> out_list2(out_data2, 3);
    LinkedList<int> sub_list115(*(list15.GetSubList(1, 3)));
    try {
        if (sub_list115 != out_list2) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 1.16 Проверка правильности создания подсписка
    LinkedList<int> sub_list116(*(list15.GetSubList(0, 4)));
    try {
        if (sub_list116 != out_list1) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 1.17 Проверка правильности создания подсписка
    LinkedList<int> sub_list117(*(list15.GetSubList(2, 2)));
    try {
       if (sub_list117[0] != 2) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 1.18 Проверка воврата ошибок GetSubList
    try {
        LinkedList<int> sub_list118(*(list15.GetSubList(3, 2)));
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 1.19 Проверка воврата ошибок GetSubList
    try {
        LinkedList<int> sub_list119(*(list15.GetSubList(-1, 2)));
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 1.20 Проверка воврата ошибок GetSubList
    try {
        LinkedList<int> sub_list120(*(list15.GetSubList(1, 5)));
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 1.21 Проверка корректности Append
    try {
        list15.Append(5);
        if (list15[5] != 5) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 1.22 Проверка корректности Prepend
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

    result_of_test = 0; //TEST 1.23 Проверка корректности InsertAt
    try {
        list122.InsertAt(10, 3);
        if (list122[3] != 10) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 1.24 Проверка возврата ошибок InsertAt
    try {
        list122.InsertAt(10, 9);
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 1.25 Проверка возврата ошибок InsertAt
    try {
        list122.InsertAt(10, -1);
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 1.26 Проверка корректности InsertAt
    try {
        list122.InsertAt(11, 8);
        if (list122[8] != 11) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 1.27 Проверка корректности InsertAt
    try {
        list122.InsertAt(12, 0);
        if (list122[0] != 12) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 1.28 Проверка Concat
    int data1[5] = {0, 1, 2, 3, 4};
    int data2[3] = {5, 6, 7};
    int out_data3[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    LinkedList<int> out_list3(out_data3, 8);
    LinkedList<int> list128_1(data1, 5);
    LinkedList<int> list128_2(data2, 3);
    try {
        list128_1.Concat(&list128_2);
        if (list128_1.GetLength() != 8) result_of_test = 1;
        if (list128_1 != out_list3) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 1.29 Проверка Concat
    LinkedList<int> list129_1(data1, 5);
    LinkedList<int> list129_2;
    try {
        list129_1.Concat(&list129_2);
        if (list129_1.GetLength() != 5) result_of_test = 1;
        if (list129_1 != out_list1) result_of_test = 1;       
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 1.30 Проверка Concat
    LinkedList<int> list130_1;
    LinkedList<int> list130_2(data1, 5);
    try {
        list130_1.Concat(&list130_2);
        if (list130_1.GetLength() != 5) result_of_test = 1;
        if (list130_1 != out_list1) result_of_test = 1;     
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 1.31 Проверка правильности Delete
    int out_data4[4] = {0, 1, 2, 4};
    LinkedList<int> out_list4(out_data4, 4);
    LinkedList<int> list131(data1, 5);
    try {
        list131.Delete(3);
        if (list131.GetLength() != 4) result_of_test = 1;
        if (list131 != out_list4) result_of_test = 1;     
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 1.32 Проверка правильности Delete
    int out_data5[4] = {0, 1, 2, 3};
    LinkedList<int> out_list5(out_data5, 4);
    LinkedList<int> list132(data1, 5);
    try {
        list132.Delete(4);
        if (list132.GetLength() != 4) result_of_test = 1;
        if (list132 != out_list5) result_of_test = 1;     
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 1.33 Проверка правильности Delete
    int out_data6[4] = {1, 2, 3, 4};
    LinkedList<int> out_list6(out_data6, 4);
    LinkedList<int> list133(data1, 5);
    try {
        list133.Delete(0);
        if (list133.GetLength() != 4) result_of_test = 1;
        if (list133 != out_list6) result_of_test = 1;     
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 1.34 Проверка возврата ошибок Delete
    LinkedList<int> list134(data1, 5);
    try {
        list134.Delete(-1);
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 1.35 Проверка возврата ошибок Delete
    LinkedList<int> list135(data1, 5);
    try {
        list135.Delete(5);
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 1.36 Проверка возврата ошибок Delete
    LinkedList<int> list136;
    try {
        list136.Delete(0);
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 1.37 Проверка добавления после Delete
    int out_data7[5] = {0, 1, 2, 4, 9};
    LinkedList<int> out_list7(out_data7, 5);
    LinkedList<int> list137(data1, 5);
    try {
        list137.Delete(3);
        list137.Append(9);
        if (list137.GetLength() != 5) result_of_test = 1;
        if (list137 != out_list7) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 1.38 Проверка добавления после Delete
    int out_data8[5] = {0, 1, 2, 3, 9};
    LinkedList<int> out_list8(out_data8, 5);
    LinkedList<int> list138(data1, 5);
    try {
        list138.Delete(4);
        list138.Append(9);
        if (list138.GetLength() != 5) result_of_test = 1;
        if (list138 != out_list8) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 1.39 Проверка добавления после Delete
    int out_data9[5] = {1, 2, 3, 4, 9};
    LinkedList<int> out_list9(out_data9, 5);
    LinkedList<int> list139(data1, 5);
    try {
        list139.Delete(0);
        list139.Append(9);
        if (list139.GetLength() != 5) result_of_test = 1;
        if (list139 != out_list9) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 1.40 Проверка добавления после Delete
    int out_data10[5] = {9, 0, 1, 2, 4};
    LinkedList<int> out_list10(out_data10, 5);
    LinkedList<int> list140(data1, 5);
    try {
        list140.Delete(3);
        list140.Prepend(9);
        if (list140.GetLength() != 5) result_of_test = 1;
        if (list140 != out_list10) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 1.41 Проверка добавления после Delete
    int out_data11[5] = {9, 0, 1, 2, 3};
    LinkedList<int> out_list11(out_data11, 5);
    LinkedList<int> list141(data1, 5);
    try {
        list141.Delete(4);
        list141.Prepend(9);
        if (list141.GetLength() != 5) result_of_test = 1;
        if (list141 != out_list11) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 1.42 Проверка добавления после Delete
    int out_data12[5] = {9, 1, 2, 3, 4};
    LinkedList<int> out_list12(out_data12, 5);
    LinkedList<int> list142(data1, 5);
    try {
        list142.Delete(0);
        list142.Prepend(9);
        if (list142.GetLength() != 5) result_of_test = 1;
        if (list142 != out_list12) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 1.43 Проверка добавления после Delete
    LinkedList<int> list143(data1, 5);
    try {
        list143.Delete(4);
        list143.InsertAt(4, 4);
        if (list143.GetLength() != 5) result_of_test = 1;
        if (list143 != out_list1) result_of_test = 1;
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

    result_of_test = 0; //TEST 2.1 Проверка создания пустого списка
    DynamicArray<int> list21;
    if (list21.GetSize() != 0) result_of_test = 1;
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 2.2 Проверка возврата ошибок Get
    try {
        list21.Get(0);
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 2.3 Проверка возврата ошибок []
    try {
        list21[0];
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 2.4 Проверка возврата ошибок Set
    try {
        list21.Set(0, 1);
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 2.5 Проверка возврата ошибок Resize
    try {
        list21.Resize(-1);
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::NEGATIVE_QUANTITY) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 2.6 Проверка корректности Resize
    try {
        list21.Resize(3);
        if (list21.GetSize() != 3) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 2.7 Проверка корректности Set
    int out_data1[3] = {0, 1, 2};
    DynamicArray<int> out_list1(out_data1, 3);
    try {
        for (int i = 0; i < 3; i++) {
            list21.Set(i, i);
        }
        if (list21 != out_list1) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 2.8 Проверка корректности Resize
    int out_data2[2] = {0, 1};
    DynamicArray<int> out_list2(out_data2, 2);
    try {
        list21.Resize(2);
        if (list21.GetSize() != 2) result_of_test = 1;
        if (list21 != out_list2) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 2.9 Проверка корректности создания списка фиксированной длины
    DynamicArray<int> list29(5);
    try {
        if (list29.GetSize() != 5) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 2.10 Проверка Set
    int out_data3[5] = {0, 1, 2, 3, 4};
    DynamicArray<int> out_list3(out_data3, 5);
    try {
        for (int i = 0; i < 5; i++) {
            list29.Set(i, i);
        }
        if (list29 != out_list3) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 2.11 Проверка создания списка по другому списку
    int data[5] = {0, 1, 2, 3, 4};
    DynamicArray<int> list211(data, 5);
    try {
        if (list211.GetSize() != 5) result_of_test = 1;
        if (list211 != out_list3) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 2.12 Проверка возврата ошибок создания списка некорректной длины
    try {
        DynamicArray<int> list212(data, -1);
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::NEGATIVE_QUANTITY) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 2.13 Проверка возврата ошибок создания списка некорректной длины
    try {
        DynamicArray<int> list213(-1);
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::NEGATIVE_QUANTITY) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 2.14 Проверка копирования списка
    DynamicArray<int> list214(list211);
    try {
        if (list214 != out_list3) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 2.15 Проверка Set
    try {
        list214.Set(3, 6);
        if (list214[3] != 6) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 2.16 Проверка возврата ошибок Set
    try {
        list214.Set(-1, 7);
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 2.17 Проверка возврата ошибок Set
    try {
        list214.Set(5, 7);
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 2.18 Проверка Get
    try {
        if (list214.Get(1) != 1) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 2.19 Проверка возврата ошибок Get
    try {
        list214.Get(-1);
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 2.20 Проверка возврата ошибок Set
    try {
        list214.Get(5);
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 2.21 Проверка корректности Delete
    int out_data4[4] = {0, 1, 2, 4};
    DynamicArray<int> out_list4(out_data4, 4);
    DynamicArray<int> list221(data, 5);
    try {
        list221.Delete(3);
        if (list221.GetSize() != 4) result_of_test = 1;
        if (list221 != out_list4) result_of_test = 1;     
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 2.22
    int out_data5[4] = {0, 1, 2, 3};
    DynamicArray<int> out_list5(out_data5, 4);
    DynamicArray<int> list222(data, 5);
    try {
        list222.Delete(4);
        if (list222.GetSize() != 4) result_of_test = 1;
        if (list222 != out_list5) result_of_test = 1;     
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 2.23
    int out_data6[4] = {1, 2, 3, 4};
    DynamicArray<int> out_list6(out_data6, 4);
    DynamicArray<int> list223(data, 5);
    try {
        list223.Delete(0);
        if (list223.GetSize() != 4) result_of_test = 1;
        if (list223 != out_list6) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 2.24 Проверка возврата ошибок Delete
    DynamicArray<int> list224(data, 5);
    try {
        list224.Delete(-1);
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 2.25
    DynamicArray<int> list225(data, 5);
    try {
        list225.Delete(5);
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 2.26
    DynamicArray<int> list226;
    try {
        list226.Delete(0);
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 2.27 Проверка добавления после Delete
    DynamicArray<int> list227(data, 5);
    try {
        list227.Delete(4);
        list227.Resize(5);
        list227.Set(4, 4);
        if (list227 != out_list3) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;
}

void TestListSequence() { //GROUP 3
    int test_group_number = 3;
    int test_number = 1;
    int result_of_test = 0;

    result_of_test = 0; //TEST 3.1 Проверка создания пустого списка
    ListSequence<int> list31;
    try {
        if (list31.GetLength() != 0) result_of_test = 1;
    }
    catch (ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 3.2 Проверка создания списка по массиву
    int out_data1[5] = {0, 1, 2, 3, 4};
    int data[5] = {0, 1, 2, 3, 4};
    ListSequence<int> out_list1(out_data1, 5);
    ListSequence<int> list32(data, 5);
    try {
        if (list32.GetLength() != 5) result_of_test = 1;
        if (list32 != out_list1) result_of_test = 1;
    }
    catch (ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 3.3 Проверка копирования списка
    ListSequence<int> list33(list32);
    try {
        if (list33.GetLength() != 5) result_of_test = 1;
        if (list33 != out_list1) result_of_test = 1;
    }
    catch (ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 3.4 Проверка возврата ошибок []
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

    result_of_test = 1; //TEST 3.6 Проверка возврата ошибок GetFirst
    try {
        list31.GetFirst();
    }
    catch (ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 3.7 Проверка возврата ошибок GetLast
    try {
        list31.GetLast();
    }
    catch (ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 3.8 Проверка GetFirst
    try {
        if (list32.GetFirst() != 0) result_of_test = 1;
    }
    catch (ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 3.9 Проверка GetLast
    try {
        if (list32.GetLast() != 4) result_of_test = 1;
    }
    catch (ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 3.10 Проверка Get
    try {
        if (list32.Get(2) != 2) result_of_test = 1;
    }
    catch (ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 3.11 Проверка возврата ощибок Get
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

    result_of_test = 0; //TEST 3.13 Проверка создания под списка
    int out_data2[3] = {1, 2, 3};
    ListSequence<int> out_list2(out_data2, 3);
    try {
        ListSequence<int>* sub_list313 = dynamic_cast<ListSequence<int>*>(list32.GetSubsequence(1, 3));
        if ((*sub_list313) != out_list2) result_of_test = 1;
    }
    catch (ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 3.14 Проверка возврата ошибок при создания подсписка
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

    result_of_test = 0; //TEST 3.17 Проверка Append
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

    result_of_test = 0; //TEST 3.18 Проверка Prepend
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

    result_of_test = 0; //TEST 3.19 Проверка InsertAt
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

    result_of_test = 1; //TEST 3.20 Проверка возврата ошибок InsterAt
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

    result_of_test = 0; //TEST 3.22 Проверка InsertAt
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

    result_of_test = 0; //TEST 3.24 Проверка Concat
    int data1[5] = {0, 1, 2, 3, 4};
    int data2[3] = {5, 6, 7};
    int out_data3[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    ListSequence<int> out_list3(out_data3, 8);
    ListSequence<int> list324_1(data1, 5);
    ListSequence<int> list324_2(data2, 3);
    try {
        ListSequence<int>* list324_3 = dynamic_cast<ListSequence<int>*>(list324_1.Concat(&list324_2));
        if ((*list324_3).GetLength() != 8) result_of_test = 1;
        if ((*list324_3) != out_list3) result_of_test = 1;

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
        if ((*list325_3) != out_list1) result_of_test = 1;
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
        if ((*list326_3) != out_list1) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 3.27 Проверка корректности Delete
    int out_data4[4] = {0, 1, 2, 4};
    ListSequence<int> out_list4(out_data4, 4);
    ListSequence<int> list327(data1, 5);
    try {
        list327.Delete(3);
        if (list327.GetLength() != 4) result_of_test = 1;
        if (list327 != out_list4) result_of_test = 1;     
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 3.28
    int out_data5[4] = {0, 1, 2, 3};
    ListSequence<int> out_list5(out_data5, 4);
    ListSequence<int> list328(data1, 5);
    try {
        list328.Delete(4);
        if (list328.GetLength() != 4) result_of_test = 1;
        if (list328 != out_list5) result_of_test = 1;     
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 3.29
    int out_data6[4] = {1, 2, 3, 4};
    ListSequence<int> out_list6(out_data6, 4);
    ListSequence<int> list329(data1, 5);
    try {
        list329.Delete(0);
        if (list329.GetLength() != 4) result_of_test = 1;
        if (list329 != out_list6) result_of_test = 1;     
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 3.30 Проверка возврата ошибок Delete
    ListSequence<int> list330(data1, 5);
    try {
        list330.Delete(-1);
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 3.31
    ListSequence<int> list331(data1, 5);
    try {
        list331.Delete(5);
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 3.32
    ListSequence<int> list332;
    try {
        list332.Delete(0);
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 3.33 Проверка добавления после Delete
    int out_data7[5] = {0, 1, 2, 4, 9};
    ListSequence<int> out_list7(out_data7, 5);
    ListSequence<int> list333(data1, 5);
    try {
        list333.Delete(3);
        list333.Append(9);
        if (list333.GetLength() != 5) result_of_test = 1;
        if (list333 != out_list7) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 3.34
    int out_data8[5] = {0, 1, 2, 3, 9};
    ListSequence<int> out_list8(out_data8, 5);
    ListSequence<int> list334(data1, 5);
    try {
        list334.Delete(4);
        list334.Append(9);
        if (list334.GetLength() != 5) result_of_test = 1;
        if (list334 != out_list8) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 3.35
    int out_data9[5] = {1, 2, 3, 4, 9};
    ListSequence<int> out_list9(out_data9, 5);
    ListSequence<int> list335(data1, 5);
    try {
        list335.Delete(0);
        list335.Append(9);
        if (list335.GetLength() != 5) result_of_test = 1;
        if (list335 != out_list9) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 3.36
    int out_data10[5] = {9, 0, 1, 2, 4};
    ListSequence<int> out_list10(out_data10, 5);
    ListSequence<int> list336(data1, 5);
    try {
        list336.Delete(3);
        list336.Prepend(9);
        if (list336.GetLength() != 5) result_of_test = 1;
        if (list336 != out_list10) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 3.37
    int out_data11[5] = {9, 0, 1, 2, 3};
    ListSequence<int> out_list11(out_data11, 5);
    ListSequence<int> list337(data1, 5);
    try {
        list337.Delete(4);
        list337.Prepend(9);
        if (list337.GetLength() != 5) result_of_test = 1;
        if (list337 != out_list11) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 3.38
    int out_data12[5] = {9, 1, 2, 3, 4};
    ListSequence<int> out_list12(out_data12, 5);
    ListSequence<int> list338(data1, 5);
    try {
        list338.Delete(0);
        list338.Prepend(9);
        if (list338.GetLength() != 5) result_of_test = 1;
        if (list338 != out_list12) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 3.39
    ListSequence<int> list339(data1, 5);
    try {
        list339.Delete(4);
        list339.InsertAt(4, 4);
        if (list339.GetLength() != 5) result_of_test = 1;
        if (list339 != out_list1) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 3.40 Проверка вывода
    ListSequence<int> list340(data1, 5);
    try {
        std::cout << "Next line must be: [0, 1, 2, 3, 4], if it isn't test 3.40 failed" << "\n";
        std::cout << list340 << "\n";
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

    result_of_test = 0; //TEST 4.1 Проверка создания пустого списка
    ArraySequence<int> list41;
    try {
        if (list41.GetLength() != 0) result_of_test = 1;
    }
    catch (ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 4.2 Проверка создания списка по массиву
    int out_data1[5] = {0, 1, 2, 3, 4};
    int data[5] = {0, 1, 2, 3, 4};
    ArraySequence<int> out_list1(out_data1, 5);
    ArraySequence<int> list42(data, 5);
    try {
        if (list42.GetLength() != 5) result_of_test = 1;
        if (list42 != out_list1) result_of_test = 1;
    }
    catch (ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 4.3 Проверка копирования списка
    ArraySequence<int> list43(list42);
    try {
        if (list43.GetLength() != 5) result_of_test = 1;
        if (list42 != out_list1) result_of_test = 1;
    }
    catch (ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 4.4 Проверка возврата ошибок []
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

    result_of_test = 1; //TEST 4.6 Проверка возврата ошибок GetFirst
    try {
        list41.GetFirst();
    }
    catch (ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 4.7 Проверка возврата ошибок GetLast
    try {
        list41.GetLast();
    }
    catch (ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 4.8 Проверка GetFirst
    try {
        if (list42.GetFirst() != 0) result_of_test = 1;
    }
    catch (ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 4.9 Проверка GetLast
    try {
        if (list42.GetLast() != 4) result_of_test = 1;
    }
    catch (ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 4.10 Проверка Get
    try {
        if (list42.Get(2) != 2) result_of_test = 1;
    }
    catch (ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 4.11 Проверка возврата ощибок Get
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

    result_of_test = 0; //TEST 4.13 Проверка создания под списка
    int out_data2[3] = {1, 2, 3};
    ArraySequence<int> out_list2(out_data2, 3);
    try {
        ArraySequence<int>* sub_list413 = dynamic_cast<ArraySequence<int>*>(list42.GetSubsequence(1, 3));
        if ((*sub_list413) != out_list2) result_of_test = 1;
    }
    catch (ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 4.14 Проверка возврата ошибок при создания подсписка
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
    
    result_of_test = 0; //TEST 4.17 Проверка Append
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

    result_of_test = 0; //TEST 4.18 Проверка Prepend
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

    result_of_test = 0; //TEST 4.19 Проверка InsertAt
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

    result_of_test = 1; //TEST 4.20 Проверка возврата ошибок InsterAt
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

    result_of_test = 0; //TEST 4.22 Проверка InsertAt
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

    result_of_test = 0; //TEST 4.24 Проверка Concat
    int data1[5] = {0, 1, 2, 3, 4};
    int data2[3] = {5, 6, 7};
    int out_data3[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    ArraySequence<int> out_list3(out_data3, 8);
    ArraySequence<int> list424_1(data1, 5);
    ArraySequence<int> list424_2(data2, 3);
    try {
        ArraySequence<int>* list424_3 = dynamic_cast<ArraySequence<int>*>(list424_1.Concat(&list424_2));
        if ((*list424_3).GetLength() != 8) result_of_test = 1;
        if ((*list424_3) != out_list3) result_of_test = 1;
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
        if ((*list425_3) != out_list1) result_of_test = 1;
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
        if ((*list426_3) != out_list1) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 4.27 Проверка корректности Delete
    int out_data4[4] = {0, 1, 2, 4};
    ArraySequence<int> out_list4(out_data4, 4);
    ArraySequence<int> list427(data1, 5);
    try {
        list427.Delete(3);
        if (list427.GetLength() != 4) result_of_test = 1;
        if (list427 != out_list4) result_of_test = 1;     
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 4.28
    int out_data5[4] = {0, 1, 2, 3};
    ArraySequence<int> out_list5(out_data5, 4);
    ArraySequence<int> list428(data1, 5);
    try {
        list428.Delete(4);
        if (list428.GetLength() != 4) result_of_test = 1;
        if (list428 != out_list5) result_of_test = 1;     
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 4.29
    int out_data6[4] = {1, 2, 3, 4};
    ArraySequence<int> out_list6(out_data6, 4);
    ArraySequence<int> list429(data1, 5);
    try {
        list429.Delete(0);
        if (list429.GetLength() != 4) result_of_test = 1;
        if (list429 != out_list6) result_of_test = 1;     
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 4.30 Проверка возврата ошибок Delete
    ArraySequence<int> list430(data1, 5);
    try {
        list430.Delete(-1);
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 4.31
    ArraySequence<int> list431(data1, 5);
    try {
        list431.Delete(5);
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 4.32
    ArraySequence<int> list432;
    try {
        list432.Delete(0);
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 4.33 Проверка добавления после Delete
    int out_data7[5] = {0, 1, 2, 4, 9};
    ArraySequence<int> out_list7(out_data7, 5);
    ArraySequence<int> list433(data1, 5);
    try {
        list433.Delete(3);
        list433.Append(9);
        if (list433.GetLength() != 5) result_of_test = 1;
        if (list433 != out_list7) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 4.34
    int out_data8[5] = {0, 1, 2, 3, 9};
    ArraySequence<int> out_list8(out_data8, 5);
    ArraySequence<int> list434(data1, 5);
    try {
        list434.Delete(4);
        list434.Append(9);
        if (list434.GetLength() != 5) result_of_test = 1;
        if (list434 != out_list8) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 4.35
    int out_data9[5] = {1, 2, 3, 4, 9};
    ArraySequence<int> out_list9(out_data9, 5);
    ArraySequence<int> list435(data1, 5);
    try {
        list435.Delete(0);
        list435.Append(9);
        if (list435.GetLength() != 5) result_of_test = 1;
        if (list435 != out_list9) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 4.36
    int out_data10[5] = {9, 0, 1, 2, 4};
    ArraySequence<int> out_list10(out_data10, 5);
    ArraySequence<int> list436(data1, 5);
    try {
        list436.Delete(3);
        list436.Prepend(9);
        if (list436.GetLength() != 5) result_of_test = 1;
        if (list436 != out_list10) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 4.37
    int out_data11[5] = {9, 0, 1, 2, 3};
    ArraySequence<int> out_list11(out_data11, 5);
    ArraySequence<int> list437(data1, 5);
    try {
        list437.Delete(4);
        list437.Prepend(9);
        if (list437.GetLength() != 5) result_of_test = 1;
        if (list437 != out_list11) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 4.38
    int out_data12[5] = {9, 1, 2, 3, 4};
    ArraySequence<int> out_list12(out_data12, 5);
    ArraySequence<int> list438(data1, 5);
    try {
        list438.Delete(0);
        list438.Prepend(9);
        if (list438.GetLength() != 5) result_of_test = 1;
        if (list438 != out_list12) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 4.39
    ArraySequence<int> list439(data1, 5);
    try {
        list439.Delete(4);
        list439.InsertAt(4, 4);
        if (list439.GetLength() != 5) result_of_test = 1;
        if (list439 != out_list1) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 4.40 Проверка вывода
    ArraySequence<int> list440(data1, 5);
    try {
        std::cout << "Next line must be: [0, 1, 2, 3, 4], if it isn't test 4.40 failed" << "\n";
        std::cout << list440 << "\n";
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

    result_of_test = 0; //TEST 5.1 Проверка создания пустого списка
    ImmutableListSequence<int> list51;
    try {
        if (list51.GetLength() != 0) result_of_test = 1;
    }
    catch (ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 5.2 Проверка создания списка по массиву
    int out_data1[5] = {0, 1, 2, 3, 4};
    int data[5] = {0, 1, 2, 3, 4};
    ImmutableListSequence<int> out_list1(out_data1, 5);
    ImmutableListSequence<int> list52(data, 5);
    try {
        if (list52.GetLength() != 5) result_of_test = 1;
        if (list52 != out_list1) result_of_test = 1;
    }
    catch (ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 5.3 Проверка копирования списка
    ImmutableListSequence<int> list53(list52);
    try {
        if (list53.GetLength() != 5) result_of_test = 1;
        if (list53 != out_list1) result_of_test = 1;
    }
    catch (ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 5.4 Проверка возврата ошибок []
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

    result_of_test = 1; //TEST 5.6 Проверка возврата ошибок GetFirst
    try {
        list51.GetFirst();
    }
    catch (ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 5.7 Проверка возврата ошибок GetLast
    try {
        list51.GetLast();
    }
    catch (ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 5.8 Проверка GetFirst
    try {
        if (list52.GetFirst() != 0) result_of_test = 1;
    }
    catch (ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 5.9 Проверка GetLast
    try {
        if (list52.GetLast() != 4) result_of_test = 1;
    }
    catch (ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 5.10 Проверка Get
    try {
        if (list52.Get(2) != 2) result_of_test = 1;
    }
    catch (ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 5.11 Проверка возврата ощибок Get
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

    result_of_test = 0; //TEST 5.13 Проверка создания под списка
    int out_data2[3] = {1, 2, 3};
    ImmutableListSequence<int> out_list2(out_data2, 3);
    try {
        ImmutableListSequence<int>* sub_list513 = dynamic_cast<ImmutableListSequence<int>*>(list52.GetSubsequence(1, 3));
        if ((*sub_list513) != out_list2) result_of_test = 1;

    }
    catch (ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 5.14 Проверка возврата ошибок при создания подсписка
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

    result_of_test = 0; //TEST 5.17 Проверка Append
    try {
        ImmutableListSequence<int>* list517 = dynamic_cast<ImmutableListSequence<int>*>(list52.Append(5));
        if ((*list517)[5] != 5) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 5.18 Проверка Prepend
    try {
        ImmutableListSequence<int>* list518 = dynamic_cast<ImmutableListSequence<int>*>(list52.Prepend(-1));
        if ((*list518)[0] != -1) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 5.19 Проверка InsertAt
    try {
        ImmutableListSequence<int>* list519 = dynamic_cast<ImmutableListSequence<int>*>(list52.InsertAt(10, 3));
        if ((*list519)[3] != 10) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 5.20 Проверка возврата ошибок InsterAt
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

    result_of_test = 0; //TEST 5.22 Проверка InsertAt
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

    result_of_test = 0; //TEST 5.24 Проверка Concat
    int data1[5] = {0, 1, 2, 3, 4};
    int data2[3] = {5, 6, 7};
    int out_data3[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    ImmutableListSequence<int> out_list3(out_data3, 8);
    ImmutableListSequence<int> list524_1(data1, 5);
    ImmutableListSequence<int> list524_2(data2, 3);
    try {
        ImmutableListSequence<int>* list524_3 = dynamic_cast<ImmutableListSequence<int>*>(list524_1.Concat(&list524_2));
        if ((*list524_3).GetLength() != 8) result_of_test = 1;
        if ((*list524_3) != out_list3) result_of_test = 1;

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
        if ((*list525_3) != out_list1) result_of_test = 1;
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
        if ((*list526_3) != out_list1) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 5.27 Проверка корректности Delete
    int out_data4[4] = {0, 1, 2, 4};
    ImmutableListSequence<int> out_list4(out_data4, 4);
    ImmutableListSequence<int> list527(data1, 5);
    try {
        ImmutableListSequence<int>* list527_tmp = dynamic_cast<ImmutableListSequence<int>*>(list527.Delete(3));
        if ((*list527_tmp).GetLength() != 4) result_of_test = 1;
        if ((*list527_tmp) != out_list4) result_of_test = 1;     
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 5.28
    int out_data5[4] = {0, 1, 2, 3};
    ImmutableListSequence<int> out_list5(out_data5, 4);
    ImmutableListSequence<int> list528(data1, 5);
    try {
        ImmutableListSequence<int>* list528_tmp = dynamic_cast<ImmutableListSequence<int>*>(list528.Delete(4));
        if ((*list528_tmp).GetLength() != 4) result_of_test = 1;
        if ((*list528_tmp) != out_list5) result_of_test = 1;     
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 5.29
    int out_data6[4] = {1, 2, 3, 4};
    ImmutableListSequence<int> out_list6(out_data6, 4);
    ImmutableListSequence<int> list529(data1, 5);
    try {
        ImmutableListSequence<int>* list529_tmp = dynamic_cast<ImmutableListSequence<int>*>(list529.Delete(0));
        if ((*list529_tmp).GetLength() != 4) result_of_test = 1;
        if ((*list529_tmp) != out_list6) result_of_test = 1;     
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 5.30 Проверка возврата ошибок Delete
    ImmutableListSequence<int> list530(data1, 5);
    try {
        list530.Delete(-1);
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 5.31
    ImmutableListSequence<int> list531(data1, 5);
    try {
        list531.Delete(5);
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 5.32
    ImmutableListSequence<int> list532;
    try {
        list532.Delete(0);
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 5.33 Проверка добавления после Delete
    int out_data7[5] = {0, 1, 2, 4, 9};
    ImmutableListSequence<int> out_list7(out_data7, 5);
    ImmutableListSequence<int> list533(data1, 5);
    try {
        ImmutableListSequence<int>* list533_tmp = dynamic_cast<ImmutableListSequence<int>*>(list533.Delete(3));
        list533_tmp = dynamic_cast<ImmutableListSequence<int>*>((*list533_tmp).Append(9));
        if ((*list533_tmp).GetLength() != 5) result_of_test = 1;
        if ((*list533_tmp) != out_list7) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 5.34
    int out_data8[5] = {0, 1, 2, 3, 9};
    ImmutableListSequence<int> out_list8(out_data8, 5);
    ImmutableListSequence<int> list534(data1, 5);
    try {
        ImmutableListSequence<int>* list534_tmp = dynamic_cast<ImmutableListSequence<int>*>(list534.Delete(4));
        list534_tmp = dynamic_cast<ImmutableListSequence<int>*>((*list534_tmp).Append(9));
        if ((*list534_tmp).GetLength() != 5) result_of_test = 1;
        if ((*list534_tmp) != out_list8) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 5.35
    int out_data9[5] = {1, 2, 3, 4, 9};
    ImmutableListSequence<int> out_list9(out_data9, 5);
    ImmutableListSequence<int> list535(data1, 5);
    try {
        ImmutableListSequence<int>* list535_tmp = dynamic_cast<ImmutableListSequence<int>*>(list535.Delete(0));
        list535_tmp = dynamic_cast<ImmutableListSequence<int>*>((*list535_tmp).Append(9));
        if ((*list535_tmp).GetLength() != 5) result_of_test = 1;
        if ((*list535_tmp) != out_list9) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 5.36
    int out_data10[5] = {9, 0, 1, 2, 4};
    ImmutableListSequence<int> out_list10(out_data10, 5);
    ImmutableListSequence<int> list536(data1, 5);
    try {
        ImmutableListSequence<int>* list536_tmp = dynamic_cast<ImmutableListSequence<int>*>(list536.Delete(3));
        list536_tmp = dynamic_cast<ImmutableListSequence<int>*>((*list536_tmp).Prepend(9));
        if ((*list536_tmp).GetLength() != 5) result_of_test = 1;
        if ((*list536_tmp) != out_list10) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 5.37
    int out_data11[5] = {9, 0, 1, 2, 3};
    ImmutableListSequence<int> out_list11(out_data11, 5);
    ImmutableListSequence<int> list537(data1, 5);
    try {
        ImmutableListSequence<int>* list537_tmp = dynamic_cast<ImmutableListSequence<int>*>(list537.Delete(4));
        list537_tmp = dynamic_cast<ImmutableListSequence<int>*>((*list537_tmp).Prepend(9));
        if ((*list537_tmp).GetLength() != 5) result_of_test = 1;
        if ((*list537_tmp) != out_list11) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 5.38
    int out_data12[5] = {9, 1, 2, 3, 4};
    ImmutableListSequence<int> out_list12(out_data12, 5);
    ImmutableListSequence<int> list538(data1, 5);
    try {
        ImmutableListSequence<int>* list538_tmp = dynamic_cast<ImmutableListSequence<int>*>(list538.Delete(0));
        list538_tmp = dynamic_cast<ImmutableListSequence<int>*>((*list538_tmp).Prepend(9));
        if ((*list538_tmp).GetLength() != 5) result_of_test = 1;
        if ((*list538_tmp) != out_list12) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 5.39
    ImmutableListSequence<int> list539(data1, 5);
    try {
        ImmutableListSequence<int>* list539_tmp = dynamic_cast<ImmutableListSequence<int>*>(list539.Delete(4));
        list539_tmp = dynamic_cast<ImmutableListSequence<int>*>((*list539_tmp).InsertAt(4, 4));
        if ((*list539_tmp).GetLength() != 5) result_of_test = 1;
        if ((*list539_tmp) != out_list1) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 5.40
    ImmutableListSequence<int> list540(data1, 5);
    try {
        std::cout << "Next line must be: [0, 1, 2, 3, 4], if it isn't test 5.40 failed" << "\n";
        std::cout << list540 << "\n";
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

    result_of_test = 0; //TEST 6.1 Проверка создания пустого списка
    ImmutableArraySequence<int> list61;
    try {
        if (list61.GetLength() != 0) result_of_test = 1;
    }
    catch (ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 6.2 Проверка создания списка по массиву
    int out_data1[5] = {0, 1, 2, 3, 4};
    int data[5] = {0, 1, 2, 3, 4};
    ImmutableArraySequence<int> out_list1(out_data1, 5);
    ImmutableArraySequence<int> list62(data, 5);
    try {
        if (list62.GetLength() != 5) result_of_test = 1;
        if (list62 != out_list1) result_of_test = 1;
    }
    catch (ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 6.3 Проверка копирования списка
    ImmutableArraySequence<int> list63(list62);
    try {
        if (list63.GetLength() != 5) result_of_test = 1;
        if (list63 != out_list1) result_of_test = 1;
    }
    catch (ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 6.4 Проверка возврата ошибок []
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

    result_of_test = 1; //TEST 6.6 Проверка возврата ошибок GetFirst
    try {
        list61.GetFirst();
    }
    catch (ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 6.7 Проверка возврата ошибок GetLast
    try {
        list61.GetLast();
    }
    catch (ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 6.8 Проверка GetFirst
    try {
        if (list62.GetFirst() != 0) result_of_test = 1;
    }
    catch (ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 6.9 Проверка GetLast
    try {
        if (list62.GetLast() != 4) result_of_test = 1;
    }
    catch (ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 6.10 Проверка Get
    try {
        if (list62.Get(2) != 2) result_of_test = 1;
    }
    catch (ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 6.11 Проверка возврата ощибок Get
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

    result_of_test = 0; //TEST 6.13 Проверка создания под списка
    int out_data2[3] = {1, 2, 3};
    ImmutableArraySequence<int> out_list2(out_data2, 3);
    try {
        ImmutableArraySequence<int>* sub_list613 = dynamic_cast<ImmutableArraySequence<int>*>(list62.GetSubsequence(1, 3));
        if ((*sub_list613) != out_list2) result_of_test = 1;
    }
    catch (ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 6.14 Проверка возврата ошибок при создания подсписка
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

    result_of_test = 0; //TEST 6.17 Проверка Append
    try {
        ImmutableArraySequence<int>* list617 = dynamic_cast<ImmutableArraySequence<int>*>(list62.Append(5));
        if ((*list617)[5] != 5) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 6.18 Проверка Prepend
    try {
        ImmutableArraySequence<int>* list618 = dynamic_cast<ImmutableArraySequence<int>*>(list62.Prepend(-1));
        if ((*list618)[0] != -1) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 6.19 Проверка InsertAt
    try {
        ImmutableArraySequence<int>* list619 = dynamic_cast<ImmutableArraySequence<int>*>(list62.InsertAt(10, 3));
        if ((*list619)[3] != 10) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 6.20 Проверка возврата ошибок InsterAt
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

    result_of_test = 0; //TEST 6.22 Проверка InsertAt
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

    result_of_test = 0; //TEST 6.24 Проверка Concat
    int data1[5] = {0, 1, 2, 3, 4};
    int data2[3] = {5, 6, 7};
    int out_data3[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    ImmutableArraySequence<int> out_list3(out_data3, 8);
    ImmutableArraySequence<int> list624_1(data1, 5);
    ImmutableArraySequence<int> list624_2(data2, 3);
    try {
        ImmutableArraySequence<int>* list624_3 = dynamic_cast<ImmutableArraySequence<int>*>(list624_1.Concat(&list624_2));
        if ((*list624_3).GetLength() != 8) result_of_test = 1;
        if ((*list624_3) != out_list3) result_of_test = 1;
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
        if ((*list625_3) != out_list1) result_of_test = 1;
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
        if ((*list626_3) != out_list1) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 6.27 Проверка корректности Delete
    int out_data4[4] = {0, 1, 2, 4};
    ImmutableArraySequence<int> out_list4(out_data4, 4);
    ImmutableArraySequence<int> list627(data1, 5);
    try {
        ImmutableArraySequence<int>* list627_tmp = dynamic_cast<ImmutableArraySequence<int>*>(list627.Delete(3));
        if ((*list627_tmp).GetLength() != 4) result_of_test = 1;
        if ((*list627_tmp) != out_list4) result_of_test = 1;     
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 6.28
    int out_data5[4] = {0, 1, 2, 3};
    ImmutableArraySequence<int> out_list5(out_data5, 4);
    ImmutableArraySequence<int> list628(data1, 5);
    try {
        ImmutableArraySequence<int>* list628_tmp = dynamic_cast<ImmutableArraySequence<int>*>(list628.Delete(4));
        if ((*list628_tmp).GetLength() != 4) result_of_test = 1;
        if ((*list628_tmp) != out_list5) result_of_test = 1;     
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 6.29
    int out_data6[4] = {1, 2, 3, 4};
    ImmutableArraySequence<int> out_list6(out_data6, 4);
    ImmutableArraySequence<int> list629(data1, 5);
    try {
        ImmutableArraySequence<int>* list629_tmp = dynamic_cast<ImmutableArraySequence<int>*>(list629.Delete(0));
        if ((*list629_tmp).GetLength() != 4) result_of_test = 1;
        if ((*list629_tmp) != out_list6) result_of_test = 1;     
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 6.30 Проверка возврата ошибок Delete
    ImmutableArraySequence<int> list630(data1, 5);
    try {
        list630.Delete(-1);
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 6.31
    ImmutableArraySequence<int> list631(data1, 5);
    try {
        list631.Delete(5);
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 6.32
    ImmutableArraySequence<int> list632;
    try {
        list632.Delete(0);
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::INDEX_OUT_OF_RANGE) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 6.33 Проверка добавления после Delete
    int out_data7[5] = {0, 1, 2, 4, 9};
    ImmutableArraySequence<int> out_list7(out_data7, 5);
    ImmutableArraySequence<int> list633(data1, 5);
    try {
        ImmutableArraySequence<int>* list633_tmp = dynamic_cast<ImmutableArraySequence<int>*>(list633.Delete(3));
        list633_tmp = dynamic_cast<ImmutableArraySequence<int>*>((*list633_tmp).Append(9));
        if ((*list633_tmp).GetLength() != 5) result_of_test = 1;
        if ((*list633_tmp) != out_list7) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 6.34
    int out_data8[5] = {0, 1, 2, 3, 9};
    ImmutableArraySequence<int> out_list8(out_data8, 5);
    ImmutableArraySequence<int> list634(data1, 5);
    try {
        ImmutableArraySequence<int>* list634_tmp = dynamic_cast<ImmutableArraySequence<int>*>(list634.Delete(4));
        list634_tmp = dynamic_cast<ImmutableArraySequence<int>*>((*list634_tmp).Append(9));
        if ((*list634_tmp).GetLength() != 5) result_of_test = 1;
        if ((*list634_tmp) != out_list8) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 6.35
    int out_data9[5] = {1, 2, 3, 4, 9};
    ImmutableArraySequence<int> out_list9(out_data9, 5);
    ImmutableArraySequence<int> list635(data1, 5);
    try {
        ImmutableArraySequence<int>* list635_tmp = dynamic_cast<ImmutableArraySequence<int>*>(list635.Delete(0));
        list635_tmp = dynamic_cast<ImmutableArraySequence<int>*>((*list635_tmp).Append(9));
        if ((*list635_tmp).GetLength() != 5) result_of_test = 1;
        if ((*list635_tmp) != out_list9) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 6.36
    int out_data10[5] = {9, 0, 1, 2, 4};
    ImmutableArraySequence<int> out_list10(out_data10, 5);
    ImmutableArraySequence<int> list636(data1, 5);
    try {
        ImmutableArraySequence<int>* list636_tmp = dynamic_cast<ImmutableArraySequence<int>*>(list636.Delete(3));
        list636_tmp = dynamic_cast<ImmutableArraySequence<int>*>((*list636_tmp).Prepend(9));
        if ((*list636_tmp).GetLength() != 5) result_of_test = 1;
        if ((*list636_tmp) != out_list10) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 6.37
    int out_data11[5] = {9, 0, 1, 2, 3};
    ImmutableArraySequence<int> out_list11(out_data11, 5);
    ImmutableArraySequence<int> list637(data1, 5);
    try {
        ImmutableArraySequence<int>* list637_tmp = dynamic_cast<ImmutableArraySequence<int>*>(list637.Delete(4));
        list637_tmp = dynamic_cast<ImmutableArraySequence<int>*>((*list637_tmp).Prepend(9));
        if ((*list637_tmp).GetLength() != 5) result_of_test = 1;
        if ((*list637_tmp) != out_list11) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 6.38
    int out_data12[5] = {9, 1, 2, 3, 4};
    ImmutableArraySequence<int> out_list12(out_data12, 5);
    ImmutableArraySequence<int> list638(data1, 5);
    try {
        ImmutableArraySequence<int>* list638_tmp = dynamic_cast<ImmutableArraySequence<int>*>(list638.Delete(0));
        list638_tmp = dynamic_cast<ImmutableArraySequence<int>*>((*list638_tmp).Prepend(9));
        if ((*list638_tmp).GetLength() != 5) result_of_test = 1;
        if ((*list638_tmp) != out_list12) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 6.39
    ImmutableArraySequence<int> list639(data1, 5);
    try {
        ImmutableArraySequence<int>* list639_tmp = dynamic_cast<ImmutableArraySequence<int>*>(list639.Delete(4));
        list639_tmp = dynamic_cast<ImmutableArraySequence<int>*>((*list639_tmp).InsertAt(4, 4));
        if ((*list639_tmp).GetLength() != 5) result_of_test = 1;
        if ((*list639_tmp) != out_list1) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 6.40
    ImmutableArraySequence<int> list640(data1, 5);
    try {
        std::cout << "Next line must be: [0, 1, 2, 3, 4], if it isn't test 6.40 failed" << "\n";
        std::cout << list640 << "\n";
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