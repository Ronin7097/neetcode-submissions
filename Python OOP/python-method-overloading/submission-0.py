class TextProcessor:
    # Implement method overloading for format_text method
    def format_text(self,*arr):
        if len(arr)==1:
            return arr[0].upper()
        return f"{"".join(arr)}"
    



# Don't modify the code below
processor = TextProcessor()
print(processor.format_text("hello"))
print(processor.format_text("hello", "world"))
