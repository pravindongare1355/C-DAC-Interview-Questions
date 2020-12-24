package com.demo.service.impl;

import java.util.List;
import java.util.Optional;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.demo.entity.Product;
import com.demo.exception.ProductException;
import com.demo.model.ProductDetail;
import com.demo.model.ProductPrice;
import com.demo.repository.ProductRepository;
import com.demo.service.ProductService;
import com.demo.template.PriceTemplate;

@Service
public class ProductServiceImpl implements ProductService{

	@Autowired
	private ProductRepository productRepository;
	
	@Autowired
	private PriceTemplate priceTemplate;
	
	@Override
	public Product fetchProductById(final Long productId) {
		
		Optional<Product> optional = productRepository.findById(productId);
		
		return optional.orElse(new Product());
	}

	@Override
	public ProductDetail fetchProductDetails(Long productId) {
		
		// Fetch product details from DB
		Product product = fetchProductById(productId);
		
		// Fetch Product's price from PriceService
		ProductPrice productPrice = priceTemplate.fetchPrice(productId);
		
		return new ProductDetail(product, productPrice);		
	}

	
	@Override
	public List<Product> fetchProductByCategory(String category) {
		
		Optional<List<Product>> optional = productRepository.findByCategory(category);
		
		if(optional.isPresent()) {
			return optional.get();
		}
		else {
			throw new ProductException("Product Not available for Category: " + category);
		}
	}

	@Override
	public Product addProduct(Product product) {
		
		return productRepository.save(product);
	}
}
