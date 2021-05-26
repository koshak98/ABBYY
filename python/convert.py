from docx2pdf import convert

def docx_to_pdf(in_file: str, out_file: str) -> None:
    convert(in_file, out_file)