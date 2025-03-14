Bai 1:
Interchange Sort:
i = 0: 1 39 8 5 3 6 9 12 4 7 10
i = 1: 1 3 39 8 5 6 9 12 4 7 10
i = 2: 1 3 4 39 8 6 9 12 5 7 10
i = 3: 1 3 4 5 39 8 9 12 6 7 10
i = 4: 1 3 4 5 6 39 9 12 8 7 10
i = 5: 1 3 4 5 6 7 39 12 9 8 10
i = 6: 1 3 4 5 6 7 8 39 12 9 10
i = 7: 1 3 4 5 6 7 8 9 39 12 10
i = 8: 1 3 4 5 6 7 8 9 10 39 12
i = 9: 1 3 4 5 6 7 8 9 10 12 39

Selection Sort:
i = 0: 1 8 5 39 3 6 9 12 4 7 10
i = 1: 1 3 5 39 8 6 9 12 4 7 10
i = 2: 1 3 4 39 8 6 9 12 5 7 10
i = 3: 1 3 4 5 8 6 9 12 39 7 10
i = 4: 1 3 4 5 6 8 9 12 39 7 10
i = 5: 1 3 4 5 6 7 9 12 39 8 10
i = 6: 1 3 4 5 6 7 8 12 39 9 10
i = 7: 1 3 4 5 6 7 8 9 39 12 10
i = 8: 1 3 4 5 6 7 8 9 10 12 39

Insertion Sort:
i = 1: 8 39 5 1 3 6 9 12 4 7 10
i = 2: 5 8 39 1 3 6 9 12 4 7 10
i = 3: 1 5 8 39 3 6 9 12 4 7 10
i = 4: 1 3 5 8 39 6 9 12 4 7 10
i = 5: 1 3 5 6 8 39 9 12 4 7 10
i = 6: 1 3 5 6 8 9 39 12 4 7 10
i = 7: 1 3 5 6 8 9 12 39 4 7 10
i = 8: 1 3 4 5 6 8 9 12 39 7 10
i = 9: 1 3 4 5 6 7 8 9 12 39 10
i = 10: 1 3 4 5 6 7 8 9 10 12 39

Bubble Sort:
i = 0: 8 5 1 3 6 9 12 4 7 10 39
i = 1: 5 1 3 6 8 9 4 7 10 12 39
i = 2: 1 3 5 6 8 4 7 9 10 12 39
i = 3: 1 3 5 6 4 7 8 9 10 12 39
i = 4: 1 3 5 4 6 7 8 9 10 12 39
i = 5: 1 3 4 5 6 7 8 9 10 12 39


câu 2
A.Quick Sort 
 Dãy số n : 8, 5, 1, 3, 6, 9, 12, 4, 7, 10

Chọn p= 6
Ta có:  5, 1, 3, 4   6   8, 9, 12, 7, 10  (1)
	          Nhóm 1	    nhóm 2

Nhóm 1: 5, 1, 3, 4
Chọn p= 4
Ta có:  1, 3, 4, 5
Trong đó ta vẫn có (1,3) nhưng đã cùng chiều nên không xét.
=>1, 3, 4, 5 (2)

Nhóm 2: 8, 9, 12, 7, 10
Chọn p= 10
Ta có: 8, 9, 7, 10, 12
Xét (8,9,7), ta chọn p = 8
Ta được: 7,8,9

=> 7, 8, 9, 10, 12 (3)
Từ (1), (2), (3) ta được: 1, 3, 4, 5, 6, 7, 8, 9, 10, 12 

Merge Sort
 Dãy số n : 8, 5, 1, 3, 6, 9, 12, 4, 7, 10

Ta chia ra 2 nhóm : ( 8, 5, 1, 3, 6) và (9, 12, 4, 7, 10)
			                    	Nhóm1           nhóm2

Nhóm 1: ta chia ra (8, 5) và (1, 3, 6)
Bắt đầu với (8, 5) ta tách ra {8} và {5} và gộp lại  (5,8) (1)
Còn (1, 3, 6) ta tách ra {1} và (3, 6), với (3, 6) ta tách ra {3} và {6} và gộp lại thành (3,6). Xong ta lại gộp với {1} thành (1,3,6) (2)

Từ (1) và (2) ta gộp lại thành (1,3,5,6,8) (5)

Nhóm 2: ta chia ra (9, 12) và (4, 7, 10)
Bắt đầu với (9, 12) ta tách ra {9} và {12} và gộp lại thành (9, 12)  (3)
Còn (4, 7, 10) ta tách ra {4} và (7, 10 ), với (7,10) ta tách ra {7} và {10} rồi gộp là thành (7,10). xong ta lại gộp với {4} để thành (4, 7, 10) (4)
Từ (3) và (4) ta gộp lại thành (4, 7, 9, 10, 12) (6)


Từ (5) và (6) ta gộp lại thành (1,3,4,5,6,7,8,9,10,12)


 Heap Sort 
Heap Sort sử dụng cấu trúc dữ liệu heap (cây nhị phân đầy đủ) để sắp xếp dãy số.
Bước 1: Xây dựng heap từ dãy ban đầu (tạo Max-Heap, nơi mỗi nút cha lớn hơn hoặc bằng các nút con).
Dãy ban đầu:
[8, 5, 1, 3, 6, 9, 12, 4, 7, 10]
Bước 2: Đổi chỗ phần tử gốc (max) với phần tử cuối cùng trong heap, sau đó giảm kích thước heap đi một phần tử.
Tiếp tục "heapify" lại dãy.
Bước 3: Lặp lại các bước cho đến khi heap chỉ còn một phần tử.
Kết quả cuối cùng là dãy đã sắp xếp.
Kết quả cuối cùng của Heap Sort:
[1, 3, 4, 5, 6, 7, 8, 9, 10, 12]
