import sys

def longest_sorted_subarray(arr):
    start = 0
    end = 0
    curr_start = 0
    curr_len = 1
    max_len = 1

    i = 0
    while i < len(arr) - 1:
        len_sort = 0
        trigger = False

        while i < len(arr) - 1 and arr[i] < arr[i + 1]:
            if not trigger:
                curr_len = 0
                curr_start = i
                trigger = True
            len_sort += 1
            i += 1

        if len_sort > max_len:
            max_len = len_sort
            start = curr_start
            end = i

        i += 1

    print("Longest sorted subarray:", arr[start:end + 1])

def main():
    if len(sys.argv) < 2:
        print("Usage:", sys.argv[0], "<list of integers>")
        return

    try:
        arr = list(map(int, sys.argv[1:]))
        longest_sorted_subarray(arr)
    except ValueError:
        print("Invalid input. Please provide a list of integers.")

if __name__ == "__main__":
    main()