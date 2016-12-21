all: address forward backward turn_R turn_L camera up
address:addressing.c rs232.c control.c
	gcc addressing.c rs232.c control.c -Wall -Wextra -o2 -o address
forward:forward.c rs232.c control.c
	gcc forward.c rs232.c control.c -Wall -Wextra -o2 -o forward
backward:backward.c rs232.c control.c
	gcc backward.c rs232.c control.c -Wall -Wextra -o2 -o backward
turn_R:turn_R.c rs232.c control.c
	gcc turn_R.c rs232.c control.c -Wall -Wextra -o2 -o turn_R
turn_L:turn_L.c rs232.c control.c
	gcc turn_L.c rs232.c control.c -Wall -Wextra -o2 -o turn_L
camera:camera.c rs232.c control.c
	gcc camera.c rs232.c control.c -Wall -Wextra -o2 -o camera
up:up.c rs232.c control.c
	gcc up.c rs232.c control.c -Wall -Wextra -o2 -o up
