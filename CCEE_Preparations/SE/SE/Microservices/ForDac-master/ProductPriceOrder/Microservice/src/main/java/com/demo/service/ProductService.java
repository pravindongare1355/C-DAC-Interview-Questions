package com.demo.service;
import java.util.List;

import org.springframework.stereotype.Service;

import com.demo.entity.Product;
import com.demo.model.ProductDetail;

@Service
public interface ProductService {

	Product addProduct(Product product);
	
	Product fetchProductById(final Long id);
	
	ProductDetail fetchProductDetails(final Long productId);
	
	List<Product> fetchProductByCategory(String category);
}
