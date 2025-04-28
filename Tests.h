#pragma once
#include "Errors.h"
#include "Sequence.h"
#include "ArraySequence.h"
#include "ListSequence.h"
#include "ImmutableArraySequence.h"
#include "ImmutableListSequence.h"
#include "LinkedList.h"
#include "DynamicArray.h"

#include <iostream>
#include <string>

void TestResultPrint(int result_of_test, int test_group_number, int test_number);
void TestLinkedList();               //Test group 1
void TestDynamicArray();             //Test group 2
void TestListSequence();             //Test group 3
void TestArraySequence();            //Test group 4
void TestImmutableListSequence();    //Test group 5
void TestImmutableArraySequence();   //Test group 6
void TestAll();
