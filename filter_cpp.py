import os
import shutil

# Path to your directory containing the files
source_dir = r"C:\Users\Rishabh Jain\Documents\rishabh_pc\Documents\vs code cpp"

# Ensure the source directory exists
if not os.path.exists(source_dir):
    print(f"Source directory {source_dir} does not exist.")
    exit(1)

# List of folder names to create (A, B, C, ..., Z)
folders = [chr(i) for i in range(ord('A'), ord('J') + 1)]

# Create folders and organize files
for folder in folders:
    folder_path = os.path.join(source_dir, folder)
    os.makedirs(folder_path, exist_ok=True)  # Create the folder if it doesn't exist

    # Move files with the matching prefix to the corresponding folder
    for filename in os.listdir(source_dir):
        if filename.startswith(f"{folder}_"):
            source_file = os.path.join(source_dir, filename)
            target_file = os.path.join(folder_path, filename)
            shutil.move(source_file, target_file)

print("Files successfully organized into folders.")
