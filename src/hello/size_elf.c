static bfd_size_type bsssize;
static bfd_size_type datasize;
static bfd_size_type textsize;

static void
berkeley_sum (abfd, sec, ignore)
     bfd *abfd ATTRIBUTE_UNUSED;
     sec_ptr sec;
     PTR ignore ATTRIBUTE_UNUSED;
{
  flagword flags;
  bfd_size_type size;

  flags = bfd_get_section_flags (abfd, sec);
  if ((flags & SEC_ALLOC) == 0)
    return;

  size = bfd_get_section_size_before_reloc (sec);
  if ((flags & SEC_CODE) != 0 || (flags & SEC_READONLY) != 0)
    textsize += size;
  else if ((flags & SEC_HAS_CONTENTS) != 0)
    datasize += size;
  else
    bsssize += size;
}
