def fibonacci_series(n: int) -> list[int]:
    """
    Generate a Fibonacci series of n terms.

    Args:
        n (int): Number of terms to generate.

    Returns:
        list[int]: List containing the Fibonacci series.
    """
    series = []
    a, b = 0, 1

    for _ in range(n):
        series.append(a)
        a, b = b, a + b

    return series


def main():
    try:
        user_input = input("Enter the number of terms: ")
        
        # Security: Validate input to avoid injection or crash
        if not user_input.isdigit():
            raise ValueError("Input must be a positive integer.")

        num_terms = int(user_input)

        if num_terms <= 0:
            raise ValueError("Number of terms must be greater than zero.")

        fib_series = fibonacci_series(num_terms)
        print("Fibonacci Series:")
        print(" ".join(map(str, fib_series)))

    except ValueError as ve:
        print(f"Invalid input: {ve}")
    except Exception as e:
        print(f"An unexpected error occurred: {e}")


if __name__ == "__main__":
    main()
