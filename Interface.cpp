#include "Interface.h"
static std::vector<Sequence<int>*> seqs;

static void PrintError(ErrorCode ex);

void Menu(){
    int exit_sign = 0;
    while (exit_sign == 0) {
        exit_sign = Home_Page();
    }
    printf("Goodbye\n");
}

int Home_Page(){
    int com;

    std::cout << "Enter a number to select what you want to do.\n";
    std::cout << "1 - Create a new Sequence and fill it in.\n";
    std::cout << "2 - Delete existing Sequence.\n";
    std::cout << "3 - Delete element from Sequence.\n";
    std::cout << "4 - Print Sequence to terminal.\n";
    std::cout << "5 - Print how many Sequence exist.\n";
    std::cout << "6 - Print one element from Sequence.\n";
    std::cout << "7 - Print length of Sequence.\n";
    std::cout << "8 - Get sub Sequence from Sequence and write it in free space\n";
    std::cout << "9 - Append element to Seq\n";
    std::cout << "10 - Prepend element to Seq\n";
    std::cout << "11 - Insert element to Seq\n";
    std::cout << "12 - Concat two Sequences and write it in free space\n";
    std::cout << "13 - Exit\n";
    
    int continue_input = 1;
    while (continue_input == 1) {
        try{
            std::cout << "Enter the number of operation: ";
            std::cin >> com;

            switch(com){
                case 1:
                    CreateNewSeq();
                    continue_input = 0;
                    break;
                case 2:
                    DeleteExistingSeq();
                    continue_input = 0;
                    break;
                case 3:
                    DeleteElemFromSeq();
                    continue_input = 0;
                    break;
                case 4:
                    PrintSeq();
                    continue_input = 0;
                    break;
                case 5:
                    PrintQntOfSeq();
                    continue_input = 0;
                    break;
                case 6:
                    GetFromSeq();
                    continue_input = 0;
                    break;
                case 7:
                    GetLengthSeq();
                    continue_input = 0;
                    break;
                case 8:
                    GetSubSeqFromSeq();
                    continue_input = 0;
                    break;
                case 9:
                    AppendToSeq();
                    continue_input = 0;
                    break;
                case 10:
                    PrependToSeq();
                    continue_input = 0;
                    break;
                case 11:
                    InsertAtSeq();
                    continue_input = 0;
                    break;
                case 12:
                    ConcatTwoSeq();
                    continue_input = 0;
                    break;
                case 13:
                    DeleteAllSeq();
                    return 1;
                    break;
                default:
                    std::cout << "Incorrect input number\n";
            }
        }
        catch (ErrorCode ex){
            PrintError(ex);
        }
    }
    return 0;
}

void CreateNewSeq() {
    std::cout << "Choose type:\n"
              << "1 - ArraySequence\n"
              << "2 - ListSequence\n"
              << "3 - ImmutableArraySequence\n"
              << "4 - ImmutableListSequence\n"
              << "Enter: ";
    int type;
    std::cin >> type;
    Sequence<int>* new_seq = nullptr;

    switch (type) {
        case 1: {
            new_seq = new ArraySequence<int>();
            std::cout << "Created ArraySequence his number is " << seqs.size() << "\n";
            break;
        }
        case 2: {
            new_seq = new ListSequence<int>();
            std::cout << "Created ListSequence his number is " << seqs.size() << "\n";
            break;
        }
        case 3: {
            std::cout << "Enter size of ImmutableArraySequence: ";
            int n;
            std::cin >> n;
            if (n < 0) throw(ErrorCode::NEGATIVE_QUANTITY);
            int* arr = new int[n];
            for (int i = 0; i < n; i++) {
                std::cout << "Enter element number " << i << ": ";
                std::cin >> arr[i];
            }
            new_seq = new ImmutableArraySequence<int>(arr, n);
            delete[] arr;
            std::cout << "Created ImmutableArraySequence his number is " << seqs.size() << "\n";
            break;
        }
        case 4: {
            std::cout << "Enter size of ImmutableList: ";
            int n;
            std::cin >> n;
            if (n < 0) throw(ErrorCode::NEGATIVE_QUANTITY);
            int* arr = new int[n];
            for (int i = 0; i < n; i++) {
                std::cout << "Enter element number " << i << ": ";
                std::cin >> arr[i];
            }
            new_seq = new ImmutableListSequence<int>(arr, n);
            delete[] arr;
            std::cout << "Created ImmutableListSequence his number is " << seqs.size() << "\n";
            break;
        }
        default:
            std::cout << "Incorrect input number\n";
        }

    seqs.push_back(new_seq);
}

void DeleteExistingSeq() {
    if (seqs.empty()) {
        std::cout << "No sequences.\n";
        return;
    }

    std::cout << "Existing sequences: 0.." << (seqs.size()-1) << "\n";
    std::cout << "Enter number of sequence that you whant to remove: ";
    int num;
    std::cin >> num;
    if (num < 0 || num >= (int)seqs.size()) throw(ErrorCode::INDEX_OUT_OF_RANGE);
    delete seqs[num];
    seqs.erase(seqs.begin() + num);
    std::cout << "Removed sequnce number " << num << "\n";
}

void DeleteElemFromSeq() {
    if (seqs.empty()) {
        std::cout << "No sequences.\n";
        return;
    }

    std::cout << "Existing sequences: 0.." << (seqs.size()-1) << "\n";
    std::cout << "Enter number of sequence from that you whant to delete element: ";
    int num;
    std::cin >> num;
    if (num < 0 || num >= (int)seqs.size()) throw(ErrorCode::INDEX_OUT_OF_RANGE);

    std::cout << "Enter index of element that you whant to delete: ";
    int index;
    std::cin >> index;

    seqs[num] = seqs[num]->Delete(index);
    std::cout << "Element by index " << index << " was deleted from sequence " << num << "\n";
}

void DeleteAllSeq() {
    int size = (int)seqs.size();
    for (int i = 0; i < size; i++) {
        delete seqs[i];
    }
}

void PrintSeq() {
    if (seqs.empty()) {
        std::cout << "No sequences.\n";
        return;
    }
    std::cout << "Existing sequences: 0.." << (seqs.size()-1) << "\n";
    std::cout << "Enter number of sequence that you whant to print: ";
    int num;
    std::cin >> num;
    std::cout << *seqs[num] << "\n";
}

void PrintQntOfSeq() {
    if (seqs.empty()) {
        std::cout << "No sequences.\n";
        return;
    }
    std::cout << "Number of sequences: " << (int)seqs.size() << "\n";
}

void GetFromSeq() {
    if (seqs.empty()) {
        std::cout << "No sequences.\n";
        return;
    }
    std::cout << "Existing sequences: 0.." << (seqs.size()-1) << "\n";
    std::cout << "Enter number of sequence from that you whant to print: ";
    int num;
    std::cin >> num;
    if (num < 0 || num >= (int)seqs.size()) throw(ErrorCode::INDEX_OUT_OF_RANGE);
    std::cout << "Enter index of element that you whant to print: ";
    int index;
    std::cin >> index;
    std::cout << "Element index " << index << ": " << seqs[num]->Get(index) << "\n";
}

void GetLengthSeq() {
    if (seqs.empty()) {
        std::cout << "No sequences.\n";
        return;
    }
    std::cout << "Existing sequences: 0.." << (seqs.size()-1) << "\n";
    std::cout << "Enter number of sequence length you whant to print: ";
    int num;
    std::cin >> num;
    if (num < 0 || num >= (int)seqs.size()) throw(ErrorCode::INDEX_OUT_OF_RANGE);
    std::cout << "Sequence length: " << seqs[num]->GetLength() << "\n";
}

void GetSubSeqFromSeq() {
    if (seqs.empty()) {
        std::cout << "No sequences.\n";
        return;
    }
    std::cout << "Existing sequences: 0.." << (seqs.size()-1) << "\n";
    std::cout << "Enter number of sequence from that you whant to take subsequence: ";
    int num;
    std::cin >> num;
    if (num < 0 || num >= (int)seqs.size()) throw(ErrorCode::INDEX_OUT_OF_RANGE);
    std::cout << "Enter first index of subsequence: ";
    int f;
    std::cin >> f;
    std::cout << "Enter last index of subsequence: ";
    int l;
    std::cin >> l;

    Sequence<int>* new_seq = seqs[num]->GetSubsequence(f, l);
    seqs.push_back(new_seq);
    std::cout << "Subsequence added his number is " << (seqs.size() - 1) << "\n";
}

void AppendToSeq() {
    if (seqs.empty()) {
        std::cout << "No sequences.\n";
        return;
    }
    std::cout << "Existing sequences: 0.." << (seqs.size()-1) << "\n";
    std::cout << "Enter number of sequence to that you whant to append: ";
    int num;
    std::cin >> num;
    if (num < 0 || num >= (int)seqs.size()) throw(ErrorCode::INDEX_OUT_OF_RANGE);

    std::cout << "That value to append: ";
    int v;
    std::cin >> v;

    seqs[num] = seqs[num]->Append(v);
    std::cout << "Appended " << v << " to seq number " << num << "\n";
}

void PrependToSeq() {
    if (seqs.empty()) {
        std::cout << "No sequences.\n";
        return;
    }
    std::cout << "Existing sequences: 0.." << (seqs.size()-1) << "\n";
    std::cout << "Enter number of sequence to that you whant to prepend: ";
    int num;
    std::cin >> num;
    if (num < 0 || num >= (int)seqs.size()) throw(ErrorCode::INDEX_OUT_OF_RANGE);

    std::cout << "That value to prepend: ";
    int v;
    std::cin >> v;

    seqs[num] = seqs[num]->Prepend(v);
    std::cout << "Prepended " << v << " to seq number " << num << "\n";
}

void InsertAtSeq() {
    if (seqs.empty()) {
        std::cout << "No sequences.\n";
        return;
    }
    std::cout << "Existing sequences: 0.." << (seqs.size()-1) << "\n";
    std::cout << "Enter number of sequence to that you whant to insert at: ";
    int num;
    std::cin >> num;
    if (num < 0 || num >= (int)seqs.size()) throw(ErrorCode::INDEX_OUT_OF_RANGE);

    std::cout << "That value to insert at: ";
    int v;
    std::cin >> v;

    std::cout << "That index where to insert at: ";
    int index;
    std::cin >> index;

    seqs[num] = seqs[num]->InsertAt(v, index);
    std::cout << "Inserted " << v << " to seq number " << num << "to position " << index + 1 << "\n";
}

void ConcatTwoSeq() {
    if ((int)seqs.size() < 2) {
        std::cout << "2 sequences does't exist.\n";
        return;
    }

    std::cout << "Existing sequences: 0.." << (seqs.size()-1) << "\n";
    std::cout << "Enter number of first sequence that you whant to concat: ";
    int num1;
    std::cin >> num1;
    if (num1 < 0 || num1 >= (int)seqs.size()) throw(ErrorCode::INDEX_OUT_OF_RANGE);

    std::cout << "Enter number of second sequence that you whant to concat: ";
    int num2;
    std::cin >> num2;
    if (num2 < 0 || num2 >= (int)seqs.size()) throw(ErrorCode::INDEX_OUT_OF_RANGE);

    if (num1 == num2) {
        std::cout << "Ented different sequences.\n";
        return;
    }

    Sequence<int>* new_seq = seqs[num1]->Concat(seqs[num2]);
    seqs.push_back(new_seq);
    std::cout << "Sequence added his number is " << (seqs.size() - 1) << "\n";
}

static void PrintError(ErrorCode ex) {
    switch (ex) {
        case ErrorCode::OK:
            std::cout << "\nOperation is ok\n";
            break;
        case ErrorCode::INVALID_INPUT:
            std::cout << "\nInvalid input\n";
            break;
        case ErrorCode::INDEX_OUT_OF_RANGE:
            std::cout << "\nIndex out of range\n";
            break;
        case ErrorCode::NEGATIVE_QUANTITY:
            std::cout << "\nNegative quantity\n";
            break;
        case ErrorCode::MEMORY_ALLOCATION_FAILED:
            std::cout << "\nMemory allocation failed\n";
            break;
    }
}