#include <Python.h>

void print_python_bytes(PyObject *p) {
    printf("[.] bytes object info\n");
    if (!PyBytes_Check(p)) {
        printf("  [ERROR] Invalid Bytes Object\n");
        return;
    }

    Py_ssize_t size = PyBytes_Size(p);
    printf("  size: %zd\n", size);

    char *str = PyBytes_AsString(p);

    printf("  trying string: %s\n", str);

    printf("  first 10 bytes:");
    for (Py_ssize_t i = 0; i < size && i < 10; ++i) {
        printf(" %02x", str[i] & 0xff);
    }
    printf("\n");
}

void print_python_list(PyObject *p) {
    Py_ssize_t size = PyList_Size(p);
    Py_ssize_t allocated = ((PyListObject *)p)->allocated;

    printf("[*] Python list info\n");
    printf("[*] Size of the Python List = %zd\n", size);
    printf("[*] Allocated = %zd\n", allocated);

    for (Py_ssize_t i = 0; i < size; ++i) {
        PyObject *element = PyList_GetItem(p, i);
        printf("Element %zd: ", i);

        if (PyBytes_Check(element)) {
            printf("bytes\n");
            print_python_bytes(element);
        } else if (PyFloat_Check(element)) {
            printf("float\n");
        } else if (PyTuple_Check(element)) {
            printf("tuple\n");
        } else if (PyList_Check(element)) {
            printf("list\n");
            print_python_list(element);
        } else if (PyLong_Check(element)) {
            printf("int\n");
        } else if (PyUnicode_Check(element)) {
            printf("str\n");
        } else {
            printf("unknown\n");
        }
    }
}
