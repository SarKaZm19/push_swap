import sys

def longest_sorted_subarray(arr):
    n = len(arr)
    start = 0
    max_length = 1
    curr_length = 1

    for i in range(1, n):
        if arr[i] > arr[i - 1]:
            curr_length += 1
            if curr_length > max_length:
                max_length = curr_length
                start = i - max_length + 1
        else:
            curr_length = 1

    if max_length >= 2:
        return arr[start:start + max_length]
    else:
        return "No sorted subarray found."

def main():
    if len(sys.argv) < 2:
        print("Usage:", sys.argv[0], "<list of integers>")
        return

    try:
        arr = list(map(int, sys.argv[1:]))
        result = longest_sorted_subarray(arr)
        if isinstance(result, list):
            print("Longest sorted subarray:", result)
        else:
            print(result)
    except ValueError:
        print("Invalid input. Please provide a list of integers.")

if __name__ == "__main__":
    main()