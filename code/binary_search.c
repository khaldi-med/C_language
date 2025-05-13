Traceback (most recent call last):
  File "/home/mohammed/.local/bin/c_formatter_42", line 8, in <module>
    sys.exit(main())
             ^^^^^^
  File "/home/mohammed/c_formatter_42/c_formatter_42/__main__.py", line 43, in main
    print(run_all(content), end="")
          ^^^^^^^^^^^^^^^^
  File "/home/mohammed/c_formatter_42/c_formatter_42/run.py", line 29, in run_all
    content = clang_format(content)
              ^^^^^^^^^^^^^^^^^^^^^
  File "/home/mohammed/c_formatter_42/c_formatter_42/formatters/clang_format.py", line 74, in clang_format
    raise RuntimeError(f"clang-format error: {err.decode()}")
RuntimeError: clang-format error: Configuration file(s) do(es) not support Objective-C: /home/mohammed/code/c-language/code/.clang-format

