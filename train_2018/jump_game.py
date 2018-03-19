# jump game
test_case = int(input())
#print(test_case)
for t in range(test_case):
    # Loop test case
    # get NxN size
    N = int(input())
    #print(N)
    board = []
    answer = []
    for n in range(N):
        # get board's data
        row = input().split()
        row = [int(r) for r in row]
        board.append(row)

        # init answer
        ans_row = []
        for i in range(N):
            ans_row.append(0)
        answer.append(ans_row)

    # solve the problem
    answer[0][0] = 1
    for r in range(N):
        for c in range(N):
            #print('r :' , r, ' / c : ', c , ' / answer : ', answer[r][c], '/ jump : ' , board[r][c])
            if answer[r][c] == 1 :
                j_len = board[r][c]
                jr = r + j_len
                jc = c + j_len
                if jr < N :
                    answer[jr][c] = 1
                    #print('answer[', jr, '][', c, '] = ', 1)
                if jc < N :
                    answer[r][jc] = 1
                    #print('answer[', r, '][', jc, '] = ', 1)
    '''print('----------------------------------------')
    for i in range(N):
        print(board[i])
    print('----------------------------------------')
    for i in range(N):
        print(answer[i])'''

    if answer[N-1][N-1] == 1 :
        print('YES')
    else:
        print('NO')



