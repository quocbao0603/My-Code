## Solution E

Cho vị trí $n$ con kiến, ở mỗi vị trí có $a_i$ thức ăn, cần đặt tổ ở một vị trí thích hợp sao cho tổng thời gian các con kiến về đó là nhỏ nhất, thời gian bằng $a_i * s$ trong đó $s$ là quãng đường di chuyển.
<img src="https://i.imgur.com/yDZZ3qc.jpg" width="" height=""></img>
Giới hạn : $n \leq 5 \times 10^6, a_i \geq 0$.

Giải:
**Nhận xét:** tồn tại  1 vị trí trong số $n$ vị trí sao cho khi đặt tổ ở đó, tổng thời gian kiến từ mọi vị trí về là nhỏ nhất.

-	Bước 1: Thử đặt ở tọa độ $0$
	-	$Time = \sum_{j = 1}^{n} a_j *x_j$ trong đó $x_j$ là tọa độ.
- Bước 2: Lần lượt đặt tại các vị trí từ $i = 1$ đến $n$, 
	- Chuyển từ $i - 1$ sang  $i$:
		- $curTime +=  \sum_{j = 1}^{i - 1} a_j * (x_j - x_{j - 1})$ (nửa đầu số lượng kiến sẽ tăng thời gian di chuyển.)
		-  $curTime -=  \sum_{j = i}^{n} a_j * (x_j - x_{j - 1})$(nửa sau số lượng kiến sẽ giảm thời gian di chuyển.)
		- $result = min(result, curTime)$
